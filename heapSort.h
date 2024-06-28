#pragma once 
#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

void heapRebuild(int start, int *arr, int n);
void heapSort(int *arr, int n);
void heapRebuildComparison(int start, int *arr, int n, long long &count_comparison);
void heapSortComparison(int *arr, int n, long long &count_comparison);
double heapSortRuntime(int *arr, int n);