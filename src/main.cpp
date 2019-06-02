#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include "subdiretorio/quicksort_c.h"
#include "subdiretorio/quicksort_m3.h"
#include "subdiretorio/quicksort_pe.h"
#include "subdiretorio/quicksort_qi.h"
#include "subdiretorio/quicksort_it.h"
#include "subdiretorio/general.h"

using namespace std::chrono;

int main(int argc, char *argv[])
{
    std::ofstream output;
    output.open("output.csv", std::fstream::app);

    n_testes = 20;
    tempos_exec = new int[n_testes];

    // Semente de pseudo-aleatoriedade para vetores
    srand(time(NULL));
    // Argumentos do programa
    std::string sort_type = std::string(argv[1]), arr_type = std::string(argv[2]);
    int size = atoi(argv[3]), i, j;

    // Fazendo o vetor:
    int **arr = new int*[n_testes];

    for(i = 0; i < n_testes; i++) {
        if(arr_type == "Ale") {
            arr[i] = MakeRandomArray(size);
        }
        else if(arr_type == "OrdC") {
            arr[i] = MakeSortedArray(size, 'C');
        }
        else if(arr_type == "OrdD") {
            arr[i] = MakeSortedArray(size, 'D');
        }
    }

    int **arr_desord = nullptr;
    if(argc == 5 && std::string(argv[4]) == "-p")
        arr_desord = CopyArray(arr, size, n_testes);

    // Ordenando:
    for(i = 0; i < n_testes; i++) {
        auto start = high_resolution_clock::now();
        if(sort_type == "QC")
            QuicksortClassico(arr[i], size);
        else if(sort_type == "QM3")
            QuicksortM3(arr[i], size);
        else if(sort_type == "QPE")
            QuicksortPE(arr[i], size);
        else if(sort_type == "QI1")
            QuicksortQI(arr[i], size, 1);
        else if(sort_type == "QI5")
            QuicksortQI(arr[i], size, 5);
        else if(sort_type == "QI10")
            QuicksortQI(arr[i], size, 10);
        else if(sort_type == "QNR")
            QuicksortIT(arr[i], size);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        tempos_exec[i] = int(duration.count());
    }

    QuicksortClassico(tempos_exec, n_testes);
    int tempo_mediana;
    if(n_testes%2 == 0)
        tempo_mediana = (tempos_exec[n_testes/2] + tempos_exec[n_testes/2 - 1])/2;
    else
        tempo_mediana = tempos_exec[n_testes/2]; 

    std::cout << sort_type << " " << arr_type << " " << size << " " 
            << n_comp/n_testes << " " << n_mov/n_testes << " " << tempo_mediana << std::endl;
    if(output.is_open()) {
        output << sort_type << "," << arr_type << "," << size << "," 
            << n_comp/n_testes << "," << n_mov/n_testes << "," << tempo_mediana << std::endl;
    }

    if(argc == 5 && std::string(argv[4]) == "-p")
        PrintAllArrays(arr_desord, size, n_testes);

    output.close();

    // Deletando vetores alocados
    if(arr != nullptr) {
        for(i = 0; i < n_testes; i++)
            delete[] arr[i];
        delete[] arr;
    }
    if(arr_desord != nullptr) {
        for(i = 0; i < n_testes; i++)
            delete[] arr_desord[i];
        delete[] arr_desord;
    }
    
    return 0;
}