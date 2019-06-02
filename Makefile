
tp2: main.o general.o quicksort_c.o quicksort_it.o quicksort_m3.o quicksort_pe.o quicksort_qi.o
	g++ -std=c++11 main.o general.o quicksort_c.o quicksort_it.o quicksort_m3.o quicksort_pe.o quicksort_qi.o -o tp2
	make clean

main.o: src/main.cpp
	g++ -c src/main.cpp

general.o: src/general.cpp src/subdiretorio/general.h
	g++ -c src/general.cpp

quicksort_c.o: src/quicksort_c.cpp src/subdiretorio/quicksort_c.h
	g++ -c src/quicksort_c.cpp

quicksort_it.o: src/quicksort_it.cpp src/subdiretorio/quicksort_it.h
	g++ -c src/quicksort_it.cpp

quicksort_m3.o: src/quicksort_m3.cpp src/subdiretorio/quicksort_m3.h
	g++ -c src/quicksort_m3.cpp

quicksort_pe.o: src/quicksort_pe.cpp src/subdiretorio/quicksort_pe.h
	g++ -c src/quicksort_pe.cpp

quicksort_qi.o: src/quicksort_qi.cpp src/subdiretorio/quicksort_qi.h
	g++ -c src/quicksort_qi.cpp

clean:
	rm *.o