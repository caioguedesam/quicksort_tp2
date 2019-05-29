#include <iostream>
#include "subdiretorio/quicksort_c.h"
#include "subdiretorio/quicksort_m3.h"
#include "subdiretorio/quicksort_pe.h"
#include "subdiretorio/quicksort_qi.h"
#include "subdiretorio/general.h"

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int size = 500000;
    int *arr = MakeRandomArray(size);
    int i;
    /*for(i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";*/

    std::cout << "Begin sort\n";
    QuicksortClassico(arr, size);
    for(i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    delete arr;
    return 0;
}