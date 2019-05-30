#include "subdiretorio/quicksort_pe.h"
#include "subdiretorio/general.h"

int ParticaoPE(int *arr, int begin, int end) {
    int pivot = arr[begin];
    int i = begin, j = end;

    while(i <= j) {
        while(arr[i] < pivot) {n_comp++; i++;}
        while(arr[j] > pivot) {n_comp++; j--;}
        if(i <= j) {
            Swap(arr, i, j);
            i++; j--;
        }
    }

    return i;
}

void OrdenaPE(int *arr, int begin, int end) {
    int q = ParticaoPE(arr, begin, end);
    if(begin < q-1) 
        OrdenaPE(arr, begin, q-1);
    if(end > q) 
        OrdenaPE(arr, q, end);
}

void QuicksortPE(int *arr, int size) {
    OrdenaPE(arr, 0, size-1);
}