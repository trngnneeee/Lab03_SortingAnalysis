#pragma once
#include <iostream>
#include <time.h>
#include <chrono>
using namespace std;
using namespace chrono;

int partition1(int *a, int l, int r, int &numCmpLomuto);
void quickSort1(int *a, int l, int r, int &numCmpLomuto);
void calQuickSort(int *a, int n, int &numCmp);

int partitionRunTime(int *a, int l, int r);
double quickSortRunTime(int *a, int l, int r);