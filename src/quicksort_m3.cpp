#include "subdiretorio/quicksort_m3.h"
#include "subdiretorio/general.h"

int ParticaoM3(int *arr, int begin, int end) {
    int mid = (begin + end)/2;
    int median = Median(begin, mid, end);
    int pivot = arr[median];
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

void OrdenaM3(int *arr, int begin, int end) {
    int q = ParticaoM3(arr, begin, end);
    if(begin < q-1) 
        OrdenaM3(arr, begin, q-1);
    if(end > q) 
        OrdenaM3(arr, q, end);
}

void QuicksortM3(int *arr, int size) {
    OrdenaM3(arr, 0, size-1);
}