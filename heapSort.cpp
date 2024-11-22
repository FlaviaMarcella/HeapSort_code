
#include <iostream>
#include <cstdlib>
#include <ctime>
#define TAM 100

using namespace std;

void exibeVetor(long int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

typedef struct heap{
    int vet[TAM];
    int heap_size = 0;
    int tamanho;
}Heap;

int return_pai(int i){
    return (i-1)/2;
}

int return_filho_esquerda(int i){
    return (2*i)+1;
}

int return_filho_direita(int i){
    return (2*i)+2;
}

// Função para trocar dois elementos de posição
void swap(Heap *heap, int i, int j){

    // Troca o elemento atual com seu pai
    int aux = heap->vet[i];
    heap->vet[i] = heap->vet[j];
    heap->vet[j] = aux;
}

// Função para retornar o menor filho de um nó no heap
int heapify(Heap *heap, int i) {
    int l = return_filho_esquerda(i); // Índice do filho da esquerda
    int r = return_filho_direita(i);  // Índice do filho da direita
    int largest = i; // Inicializa o menor como o próprio nó

    // Verifica se o filho da esquerda é maior que o nó atual
    if (l < heap->heap_size && heap->vet[l] > heap->vet[i]) {
        largest = l;
    }

    // Verifica se o filho da direita é maior que o maior nó encontrado até agora
    if (r < heap->heap_size && heap->vet[r] > heap->vet[largest]) {
        largest = r;
    }

    // Se o menor nó não for o nó atual, troca e continua a verificação recursivamente
    if (largest != i) {
        swap(heap, i, largest);
        heapify(heap, largest);
    }

    return largest; // Retorna o índice do maior nó
}

void buildMaxHeap(Heap *heap){
    for(int i = heap->heap_size / 2 - 1; i >= 0; i--) heapify(heap,i);
}

//usa do algoritmo da arvore heap, para ordenar os vetores, com maxHeap
void heapSort(long int arr[], int n){
    Heap heap;
    heap.heap_size = n;
    heap.tamanho = n;

    for(int i = 0; i < n; i++) heap.vet[i] = arr[i];

    buildMaxHeap(&heap);

    for(int i = n - 1; i >= 0; i--){
        swap(&heap, 0, i);
        heap.heap_size--;
        heapify(&heap, 0);
    }

    for(int i = 0; i < n; i++)arr[i] = heap.vet[i];
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
    long int n = 100; // Tamanho do vetor
    long int lim = 10000; // Limite superior para os números aleatórios

    long int arr[n]; // Declara o vetor

    geraVetor_semRepetir(arr, n, lim); // Gera o vetor sem números repetidos
    
    // Mede o tempo de execução do Merge Sort
    clock_t start_time = clock();
    heapSort(arr, n); // Ordena o vetor usando Merge Sort
    clock_t end_time = clock();
    double elapsed_time_ms = (double)(end_time - start_time) / (CLOCKS_PER_SEC / 1000);
    
    exibeVetor(arr, n); // Exibe o vetor ordenado

     // Imprime o tempo de execução do Merge Sort em milissegundos
    printf("execution time: %.4lf", elapsed_time_ms);

    return 0;
}
