#pragma once
#include <iostream>
#include <time.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>
using namespace std;
using namespace chrono;


template <class T>
void HoanVi(T& a, T& b);

void GenerateRandomData(int* a, int n);

void GenerateSortedData(int* a, int n);

void GenerateReverseData(int* a, int n);

void GenerateNearlySortedData(int* a, int n);

void GenerateData(int* a, int n, int dataType);



void showMenu();

