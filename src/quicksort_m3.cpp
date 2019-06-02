#include "subdiretorio/quicksort_m3.h"
#include "subdiretorio/general.h"

// Método de partição com mediana de 3:
int ParticaoM3(int *arr, int begin, int end) {
    // Seleciona pivô que é a mediana do primeiro, do último e do meio
    int mid = (begin + end)/2;
    int median = Median(begin, mid, end);
    int pivot = arr[median];
    int i = begin, j = end;

    // Realiza o mesmo processo de troca que a partição clássica
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

// Método de ordenação (igual o clássico, mas com seu próprio método de part.):
void OrdenaM3(int *arr, int begin, int end) {
    // Faz a partição
    int q = ParticaoM3(arr, begin, end);
    // Chamada recursiva para o subvetor à esquerda
    if(begin < q-1) 
        OrdenaM3(arr, begin, q-1);
    // Chamada recursiva para o subvetor à direita
    if(end > q) 
        OrdenaM3(arr, q, end);
}

void QuicksortM3(int *arr, int size) {
    OrdenaM3(arr, 0, size-1);
}