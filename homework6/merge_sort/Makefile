merge_sort: tests.o readFile.o mergeSort.o main.o list.o
	g++ -o merge_sort tests.o readFile.o mergeSort.o main.o list.o

tests.o: tests.cpp list.h mergeSort.h readFile.h
	g++ -c tests.cpp
readFile.o: readFile.cpp list.h
	g++ -c readFile.cpp
mergeSort.o: mergeSort.cpp list.h
	g++ -c mergeSort.cpp
main.o: main.cpp list.h tests.h readFile.h mergeSort.h
	g++ -c main.cpp
list.o: list.cpp list.h
	g++ -c list.cpp

clean:
	rm *.o