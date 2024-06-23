//Shared Sort function
#include<iostream>
#include<string>
#include<math.h>
#include<time.h>
#include"Shaker_Sort.h"
using namespace std;

void shakerSortComparision(int *arr, int n, int &comparision){
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
void calTimeShakerSort(int *arr, int n){
    clock_t begin = clock(); 
    shakerSortTime(arr, n);

    clock_t end = clock(); 
    cout<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
}