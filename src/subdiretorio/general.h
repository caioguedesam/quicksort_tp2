#ifndef GENERAL_TP2
#define GENERAL_TP2

void Swap(int *arr, int a, int b);
void PrintArray(int *arr, int size);

int Max(int a, int b);
int Min(int a, int b);
int Median(int a, int b, int c);

void Insertionsort(int *arr, int begin, int end);

int *MakeRandomArray(int size);
int *MakeSortedArray(int size, char order);

#endif