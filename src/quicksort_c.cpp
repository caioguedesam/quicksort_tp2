#include "subdiretorio/quicksort_c.h"
#include "subdiretorio/general.h"

int ParticaoClassico(int *arr, int begin, int end) {
    int mid = (begin + end)/2;
    int pivot = arr[mid];
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

void OrdenaClassico(int *arr, int begin, int end) {
    int q = ParticaoClassico(arr, begin, end);
    if(begin < q-1) 
        OrdenaClassico(arr, begin, q-1);
    if(end > q) 
        OrdenaClassico(arr, q, end);
}

void QuicksortClassico(int *arr, int size) {
    OrdenaClassico(arr, 0, size-1);
}