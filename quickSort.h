#pragma once
#include <iostream>
#include <time.h>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace chrono;

void quickSort(int *arr, int first, int last, long long &comparision);
void calQuickSort(int *arr, int n, long long &numCmp);

void quickSortRunningTime(int *arr, int first, int last);
double calQuickSortRunningTime(int *arr, int n);