#pragma once 
#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

void bubbleSort(int *arr, int n, long long &count_comparison);
double bubbleSortRuntime(int *arr, int n);