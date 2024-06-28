#pragma once 
#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

int minElement(int *arr, int n, long long &count_comparison);
int maxElement(int *arr, int n, long long &count_comparison);
void flashSortComparison(int *arr, int n, long long &count_comparison);

void flashSort(int *arr, int n);
double flashSortRuntime(int *arr, int n);