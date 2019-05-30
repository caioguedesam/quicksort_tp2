#include "subdiretorio/quicksort_it.h"
#include "subdiretorio/quicksort_c.h"

void QuicksortIT(int *arr, int size) {

    int end = size - 1, begin = 0;
    int pilha[end - begin +1];
    int top = -1;

    pilha[++top] = begin;
    pilha[++top] = end;

    while(top > -1) {
        end = pilha[top--];
        begin = pilha[top--];

        int q = ParticaoClassico(arr, begin, end);

        if(q - 1 > begin) {
            pilha[++top] = begin;
            pilha[++top] = q - 1;
        }
        if(q + 1 < end) {
            pilha[++top] = q + 1;
            pilha[++top] = end;
        }
    }
}