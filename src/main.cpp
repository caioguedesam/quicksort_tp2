#include <iostream>
#include <string>
#include "subdiretorio/quicksort_c.h"
#include "subdiretorio/quicksort_m3.h"
#include "subdiretorio/quicksort_pe.h"
#include "subdiretorio/quicksort_qi.h"
#include "subdiretorio/quicksort_it.h"
#include "subdiretorio/general.h"


int main(int argc, char *argv[])
{
    /*
    Fazer tester: repetição do teste 20 vezes
    */

    // Semente de pseudo-aleatoriedade para vetores
    srand(time(NULL));
    // Argumentos do programa
    std::string sort_type = std::string(argv[1]), arr_type = std::string(argv[2]);
    int size = atoi(argv[3]), i;


    // Fazendo o vetor:
    int *arr = nullptr;

    if(arr_type == "Ale")
        arr = MakeRandomArray(size);
    else if(arr_type == "OrdC")
        arr = MakeSortedArray(size, 'C');
    else if(arr_type == "OrdD")
        arr = MakeSortedArray(size, 'D');


    // Ordenando:
    std::cout << "Begin sort\n";

    if(sort_type == "QC")
        QuicksortClassico(arr, size);
    else if(sort_type == "QM3")
        QuicksortM3(arr, size);
    else if(sort_type == "QPE")
        QuicksortPE(arr, size);
    else if(sort_type == "QI1")
        QuicksortQI(arr, size, 1);
    else if(sort_type == "QI5")
        QuicksortQI(arr, size, 5);
    else if(sort_type == "QI10")
        QuicksortQI(arr, size, 10);
    else if(sort_type == "QNR")
        QuicksortIT(arr, size);
        

    PrintArray(arr, size);

    if(arr != nullptr)
        delete arr;
    return 0;
}