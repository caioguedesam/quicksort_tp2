#include <cstdlib>
#include <ctime>
#include <iostream>
#include "subdiretorio/general.h"

long n_comp = 0;
long n_mov = 0;
int *tempos_exec = nullptr;
int n_testes = 0;

void Swap(int *arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    n_mov += 2;
}

void PrintArray(int *arr, int size) {
    int i;
    for(i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void PrintAllArrays(int **arr, int size, int testes) {
    int i;
    for(i = 0; i < testes; i++)
        PrintArray(arr[i], size);
}

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

int Max(int a, int b) {
    return a > b ? a : b;
}

int Min(int a, int b) {
    return a < b ? a : b;
}

int Median(int a, int b, int c) {
    return Max(Min(a,b), Min(Max(a,b),c));
}

void Insertionsort(int *arr, int begin, int end) {
    int i, j;
    long aux;

    for(i = begin+1; i <= end; i++) {
        aux = arr[i];
        j = i - 1;
        while(j >= 0 && aux < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = aux;
    }
}

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