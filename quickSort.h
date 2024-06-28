#pragma once
#include <iostream>
#include <time.h>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace chrono;

int partitionRunTime(int* arr, int low, int high);
void quickSortRunTime(int* arr, int low, int high);
double calQuickSortRunTime(int* arr, int n);

int partition(int* arr, int low, int high, long long& numCmp);
void quickSort(int* arr, int low, int high, long long& numCmp);
