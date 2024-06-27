#pragma once
#include<iostream>
#include<string>
#include<math.h>
#include<time.h>
#include<chrono>

using namespace std;
using namespace chrono;

void mergeComparision(int *arr, int first, int mid, int last, int &comparision);
void mergeSortComparision(int *arr, int first, int last, int &comparision);
void calComparisionMergeSort(int *arr, int n, int &comparision);

void mergeTime(int *arr, int first, int mid, int last);
void mergeSortTime(int *arr, int first, int last);
double mergeSortRuntime(int *arr, int n);