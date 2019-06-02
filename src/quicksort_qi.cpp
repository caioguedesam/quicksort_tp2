#include "subdiretorio/quicksort_m3.h"
#include "subdiretorio/general.h"

// Método de ordenação com processo de inserção:
void OrdenaQI(int *arr, int begin, int end, int percent, int init_size) {
    // Define a porcentagem atual em relação ao tamanho original do vetor
    int current_percent = ((end - begin) * 100)/init_size;
    // Caso a partição seja menor do que a porcentagem desejada, realizar inserção
    if(current_percent < percent) {
        Insertionsort(arr, begin, end);
    }
    else {  // Caso contrário, método de ordenação igual o para mediana de 3
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