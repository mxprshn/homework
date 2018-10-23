#pragma once

#include <stdio.h>

int frequencySearch(int *sourceArray, int arrayLength);
void quickSort(int *qsSourceArray, int sortLeftBorder, int sortRightBorder);
bool programTest();
bool scanFile(FILE *inputFile, int *array, int arrayLength);