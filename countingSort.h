#include <iostream>
#include <time.h>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace chrono;

void countingSort(int *arr, int n, int &numCmp);
void countingSortRuntime(int *arr, int n);
int maxElement(int *arr, int n, int &count_comparison);