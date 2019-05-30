#include "subdiretorio/quicksort_it.h"
#include "subdiretorio/quicksort_c.h"

void QuicksortIT(int *arr, int size) {

    int end = size - 1, begin = 0;
    // Pilha para o quicksort implementada como:
    // um vetor simples:
    int pilha[end - begin +1];
    // e um índice para guardar o topo da pilha:
    int top = -1;

    // Empilhando os primeiros índices para a primeira partição
    pilha[++top] = begin;
    pilha[++top] = end;

    while(top > -1) {
        // Retirando os índices a fazer a próxima partição
        end = pilha[top--];
        begin = pilha[top--];

        int q = ParticaoClassico(arr, begin, end);

        // Guardando os próximos índices para próxima partição
        // Apenas se existirem elementos na partição
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