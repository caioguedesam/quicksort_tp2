#include "subdiretorio/quicksort_pe.h"
#include "subdiretorio/general.h"

// Método de partição com pivô sendo o primeiro elemento:
int ParticaoPE(int *arr, int begin, int end) {
    // Seleciona o pivô como sendo o primeiro elemento da partição
    int pivot = arr[begin];
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

// Método de ordenação (igual o clássico, mas com seus próprios métodos):
void OrdenaPE(int *arr, int begin, int end) {
    // Faz a partição
    int q = ParticaoPE(arr, begin, end);
    // Chamada recursiva para o subvetor à esquerda
    if(begin < q-1) 
        OrdenaPE(arr, begin, q-1);
    // Chamda recursiva para o subvetor à direita
    if(end > q) 
        OrdenaPE(arr, q, end);
}

void QuicksortPE(int *arr, int size) {
    OrdenaPE(arr, 0, size-1);
}