#pragma once 
#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

void bubbleSort(int *arr, int n, int &count_comparison);
void bubbleSortRuntime(int *arr, int n);