#pragma once
#include "bubbleSort.h"
#include "countingSort.h"
#include "flashSort.h"
#include "heapSort.h"
#include "insertionSort.h"
#include "Merge_Sort.h"
#include "quickSort.h"
#include "RadixSort.h"
#include "Selection_Sort.h"
#include "Shaker_Sort.h"
#include "ShellSort.h"
#include "DataGenerator.h"
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;

int *readFile(int &n, char *filename);
void runSort(int *arr, int n, char *algorithm, char *mode);
void writeFile(int *arr, int n, string filename);
double runSort2(int *arr, int n, char *algorithm, char *mode);