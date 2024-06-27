#pragma once 
#include<iostream>
#include<string>
#include<math.h>
#include<chrono>

using namespace std;
using namespace chrono;

void selecionSortComparision(int *arr, int n, int &comparision);
void selecionSortTime(int *arr, int n);
double calTimeSelectionSort(int *arr, int n);