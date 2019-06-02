#include "subdiretorio/quicksort_c.h"
#include "subdiretorio/general.h"

// Método clássico de partição:
int ParticaoClassico(int *arr, int begin, int end) {
    // Seleciona pivô do meio
    int mid = (begin + end)/2;
    int pivot = arr[mid];
    int i = begin, j = end;

    // Troca elementos maiores e menores do que o pivô de lugar,
    // estabelecendo as partições
    while(i <= j) {
        while(arr[i] < pivot) {n_comp++; i++;}
        while(arr[j] > pivot) {n_comp++; j--;}
        if(i <= j) {
            Swap(arr, i, j);
            i++; j--;
        }
    }

    // Retorna o índice a realizar as partições
    return i;
}

// Métoo de ordenação clássico:
void OrdenaClassico(int *arr, int begin, int end) {
    // Faz a partição
    int q = ParticaoClassico(arr, begin, end);
    // Chamada recursiva para o subvetor à esquerda
    if(begin < q-1) 
        OrdenaClassico(arr, begin, q-1);
    // Chamada recursiva para o subvetor à direita
    if(end > q) 
        OrdenaClassico(arr, q, end);
}

void QuicksortClassico(int *arr, int size) {
    OrdenaClassico(arr, 0, size-1);
}