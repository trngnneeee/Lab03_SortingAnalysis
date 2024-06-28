#include"Shaker_Sort.h"

void shakerSortComparision(int *arr, int n, long long &comparision){
    int left = 1, right = n-1, k = n-1;
    comparision = 0;
    do {
        for (int j = right; ++comparision &&  j >= left; --j){
            if (++comparision && arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                k = j;
            } 
        }
        left = k + 1;
        for (int j = left; ++comparision && j <= right; ++j){
            if (++comparision && arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                k = j;
            } 
        } 
        right = k - 1;
    }while (++comparision && left <= right);
}

void shakerSortTime(int *arr, int n){
    int left = 1, right = n-1, k = n-1;
    do {
        for (int j = right;j >= left; --j){
            if (arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                k = j;
            } 
        }
        left = k + 1;
        for (int j = left;j <= right; ++j){
            if (arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                k = j;
            } 
        } 
        right = k - 1;
    }while (left <= right);
    
}
double calTimeShakerSort(int *arr, int n){
    auto start = high_resolution_clock::now(); //start
    shakerSortTime(arr, n);

    auto stop = high_resolution_clock::now(); //stop
    auto duration = duration_cast<milliseconds>(stop - start);
    return (double)duration.count();
}