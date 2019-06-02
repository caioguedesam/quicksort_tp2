#include <cstdlib>
#include <ctime>
#include <iostream>
#include "subdiretorio/general.h"

// Biblioteca de funções utilizadas de maneira geral e não especifica de um quicksort

// Variáveis globais:
long n_comp = 0;
long n_mov = 0;
int *tempos_exec = nullptr;
int n_testes = 0;

// Método para trocar elementos de um vetor:
void Swap(int *arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    n_mov += 2;
}

// Imprimir um vetor:
void PrintArray(int *arr, int size) {
    int i;
    for(i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// Imprimir vetores de uma matriz:
void PrintAllArrays(int **arr, int size, int testes) {
    int i;
    for(i = 0; i < testes; i++)
        PrintArray(arr[i], size);
}

// Copiar vetores de uma matriz:
int **CopyArray(int **arr_origin, int size, int testes) {
    int i, j, **arr_dest = new int*[testes];
    for(i = 0; i < testes; i++) {
        arr_dest[i] = new int[size];
        for(j = 0; j < size; j++) {
            arr_dest[i][j] = arr_origin[i][j];
        }
    }

    return arr_dest;
}

// Métodos para obter a mediana:
int Max(int a, int b) {
    return a > b ? a : b;
}

int Min(int a, int b) {
    return a < b ? a : b;
}

int Median(int a, int b, int c) {
    return Max(Min(a,b), Min(Max(a,b),c));
}

// Insertion sort, usado nos Quicksorts Híbridos:
void Insertionsort(int *arr, int begin, int end) {
    int i, j;
    long aux;

    // Compara o dado elemento com os elementos anteriores,
    // posiciona se acha um elemento menor que ele
    for(i = begin+1; i <= end; i++) {
        aux = arr[i];
        j = i - 1;
        while(j >= 0 && aux < arr[j]) {
            n_comp++;
            arr[j+1] = arr[j];
            n_mov++;
            j--;
        }
        arr[j+1] = aux;
        n_mov++;
    }
}

// Métodos para preencher vetores com números aleatórios ou ordenados:
int *MakeRandomArray(int size) {
    int *arr = new int[size];
    int i;
    for(i = 0; i < size; i++)
        arr[i] = rand() % size;
    return arr;
}

int *MakeSortedArray(int size, char order) {
    int *arr = new int[size];
    int i;
    if(order == 'C') {
        for(i = 0; i < size; i++)
            arr[i] = i;
    }
    else if(order == 'D') {
        for(i = 0; i < size; i++)
            arr[i] = size - i -1;
    }
    return arr;
}