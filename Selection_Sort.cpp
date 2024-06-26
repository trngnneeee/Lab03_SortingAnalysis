#include"Selection_Sort.h"
#include<iostream>
#include<string>
#include<math.h>
#include<time.h>
using namespace std;
// calculate the comparision of selection sort

void selecionSortComparision(int *arr, int n, int &comparision){
    comparision = 0;
    for(int i = 0; ++comparision && i < n - 1 ; i++){
        int minIndex = i;
        for(int j = i + 1; ++comparision && j < n; j++){
            if(++comparision && arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void selecionSortTime(int *arr, int n){
    for(int i = 0; i < n - 1 ; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
void calTimeSelectionSort(int *arr, int n){
    clock_t begin = clock(); 
    selecionSortTime(arr, n);

    clock_t end = clock(); 
    cout<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
}