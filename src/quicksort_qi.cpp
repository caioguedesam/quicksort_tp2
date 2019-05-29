#include "subdiretorio/quicksort_m3.h"
#include "subdiretorio/general.h"

void OrdenaQI(int *arr, int begin, int end, int percent) {
    int q = ParticaoM3(arr, begin, end);
    
    if((q - begin +1) <= (end - begin +1)/(100/percent)) {
        Insertionsort(arr, q - begin +1);
    }
    else {
        if(begin < q-1) 
            OrdenaM3(arr, begin, q-1);
        if(end > q) 
            OrdenaM3(arr, q, end);
    } 
}

void QuicksortQI(int *arr, int size, int percent) {
    OrdenaQI(arr, 0, size-1, percent);
}