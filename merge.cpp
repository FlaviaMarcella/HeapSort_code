
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void exibeVetor(long int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// // Função que implementa o algoritmo Merge Sort
// void mergeSort(int arr[], int l, int r) {
//     if (l < r) {
//         int m = l + (r - l) / 2; // Calcula o ponto médio
//         // Chama mergeSort recursivamente para as duas metades
//         mergeSort(arr, l, m);
//         mergeSort(arr, m + 1, r);
//         // Mescla as duas metades
//         int i, j, k;
//         int n1 = m - l + 1;
//         int n2 = r - m;
//         // Arrays temporários para armazenar as duas metades
//         int L[n1], R[n2];
//         // Copia os dados para os arrays temporários L[] e R[]
//         for (i = 0; i < n1; i++)
//             L[i] = arr[l + i];
//         for (j = 0; j < n2; j++)
//             R[j] = arr[m + 1 + j];
//         i = 0; // Índice inicial do primeiro subarray
//         j = 0; // Índice inicial do segundo subarray
//         k = l; // Índice inicial do subarray mesclado
//         // Mescla os arrays temporários de volta em arr[l..r]
//         while (i < n1 && j < n2) {
//             if (L[i] <= R[j]) {
//                 arr[k] = L[i];
//                 i++;
//             } else {
//                 arr[k] = R[j];
//                 j++;
//             }
//             k++;
//         }
//         // Copia os elementos restantes de L[], se houver
//         while (i < n1) {
//             arr[k] = L[i];
//             i++;
//             k++;
//         }
//         // Copia os elementos restantes de R[], se houver
//         while (j < n2) {
//             arr[k] = R[j];
//             j++;
//             k++;
//         }
//     }
// }
// // Função de mesclagem usada pela função mergeSort()
// void merge(long  int arr[], long  int l, long  int m, long int r) {
//     long  int i, j, k;
//     long  int n1 = m - l + 1;
//     long  int n2 = r - m;
//     // Cria arrays temporários
//     long int L[n1], R[n2];
//     // Copia os dados para os arrays temporários L[] e R[]
//     for (i = 0; i < n1; i++)
//         L[i] = arr[l + i];
//     for (j = 0; j < n2; j++)
//         R[j] = arr[m + 1 + j];
//     // Mescla os arrays temporários de volta em arr[l..r]
//     i = 0; // Índice inicial do primeiro subarray
//     j = 0; // Índice inicial do segundo subarray
//     k = l; // Índice inicial do array mesclado
//     while (i < n1 && j < n2) {
//         if (L[i] <= R[j]) {
//             arr[k] = L[i];
//             i++;
//         }
//     else {
//         arr[k] = R[j];
//         j++;
//     }
//     k++;
// }
// // Copia os elementos restantes de L[], se houver algum
// while (i < n1) {
//     arr[k] = L[i];
//     i++;
//     k++;
// }
// // Copia os elementos restantes de R[], se houver algum
// while (j < n2) {
//     arr[k] = R[j];
//     j++;
//     k++;
// }
// }

void merge(long int arr[], long int l, long int m, long int r){

     long int i, j, k;
     long int n1 = m - l + 1;
     long int n2 = r - m;
     // Cria arrays temporários
     long int L[n1], R[n2];
     // Copia os dados para os arrays temporários L[] e R[]
     for (i = 0; i < n1; i++)
         L[i] = arr[l + i];
     for (j = 0; j < n2; j++)
         R[j] = arr[m + 1 + j];
     // Mescla os arrays temporários de volta em arr[l..r]
     i = 0; // Índice inicial do primeiro subarray
     j = 0; // Índice inicial do segundo subarray
     k = l; // Índice inicial do array mesclado
     while (i < n1 && j < n2) {
         if (L[i] <= R[j]) {
             arr[k] = L[i];
             i++;
         }
     else {
         arr[k] = R[j];
         j++;
     }
     k++;
 }
 // Copia os elementos restantes de L[], se houver algum
 while (i < n1) {
     arr[k] = L[i];
     i++;
     k++;
 }
 // Copia os elementos restantes de R[], se houver algum
 while (j < n2) {
     arr[k] = R[j];
     j++;
     k++;
 }

}

void mergeSort(long  int arr[], long int l, long int r) {
    if (l < r) {
        long int m = l + (r - l) / 2; // Calcula o índice do elemento central
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Função que gera um vetor de números aleatórios sem repetição
void geraVetor_semRepetir(long int arr[], int n, int lim) {

    if (n > lim) {
        cout << "Erro: n > lim\n";
        return;
    }

    bool usado[lim + 1] = {false}; // Array para marcar os números já usados
    srand(static_cast<unsigned int>(time(0))); // Inicializa o gerador de números aleatórios

    for (int i = 0; i < n; ++i) {
        int num;
        do {
            num = rand() % lim; // Gera um número aleatório
        } while (usado[num]); // Garante que o número não foi usado antes
        arr[i] = num; // Adiciona o número ao array
        usado[num] = true; // Marca o número como usado
    }
}

// Função principal
int main() {
    int n = 10; // Tamanho do vetor
    int lim = 100; // Limite superior para os números aleatórios

    long int arr[n]; // Declara o vetor

    geraVetor_semRepetir(arr, n, lim); // Gera o vetor sem números repetidos
    
    // Mede o tempo de execução do Merge Sort
    clock_t start_time = clock();
    mergeSort(arr, 0, n - 1); // Ordena o vetor usando Merge Sort
    clock_t end_time = clock();
    double elapsed_time_ms = (double)(end_time - start_time) / (CLOCKS_PER_SEC / 1000);
    
    exibeVetor(arr, n); // Exibe o vetor ordenado

     // Imprime o tempo de execução do Merge Sort em milissegundos
    printf("execution time: %.4lf", elapsed_time_ms);

    return 0;
}
