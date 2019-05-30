#include "subdiretorio/quicksort_m3.h"
#include "subdiretorio/general.h"

void OrdenaQI(int *arr, int begin, int end, int percent, int init_size) {
    int current_percent = ((end - begin) * 100)/init_size;
    if(current_percent < percent) {
        Insertionsort(arr, begin, end);
    }
    else {
        int q = ParticaoM3(arr, begin, end);
        if(begin < q-1) 
            OrdenaQI(arr, begin, q-1, percent, init_size);
        if(end > q) 
            OrdenaQI(arr, q, end, percent, init_size);
    } 
}

void QuicksortQI(int *arr, int size, int percent) {
    OrdenaQI(arr, 0, size-1, percent, size);
}