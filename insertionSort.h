#pragma once 
#include <iostream>
#include <time.h>
#include <chrono>
using namespace std;
using namespace chrono;

void insertionSort(int* a, int n, long long &numCmp);
double insertionSortRuntime(int* a, int n);
