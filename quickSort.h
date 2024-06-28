// #pragma once
#include <iostream>
#include <time.h>
#include <chrono>
using namespace std;
using namespace chrono;

int partitionRunTime(int *arr,int low,int high);
void quickSortRunTime(int *arr,int low,int high);

int partition(int *arr,int low,int high, int &numCmp);
void quickSort(int* arr, int low, int high, int &numCmp);