//Shared Sort function

#pragma once 
#include<iostream>
#include<string>
#include<math.h>
#include<chrono>

using namespace std;
using namespace chrono;

void shakerSortComparision(int *arr, int n, int &comparision);

void shakerSortTime(int *arr, int n);
double calTimeShakerSort(int *arr, int n);