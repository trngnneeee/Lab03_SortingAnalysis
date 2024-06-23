#include"Merge_Sort.h"
#include<iostream>
#include<string>
#include<math.h>
#include<time.h>
using namespace std;

//calculate the comparision of merge sort

void mergeComparision(int *arr, int first, int mid, int last, int &comparision){
   
    int first1 = first, last1 = mid; 
    int first2 = mid + 1, last2 = last; // The second subarray
    // Copy the smaller element into the temp array

    int *tempArr = new int[last - first + 1]; // Temporary array
    int index = first1; // Next available location in tempArr
    while ((++comparision && first1 <= last1) && (++comparision && first2 <= last2)) {
    // At this point, tempArr[first..index-1] is in order
        if ((++comparision) && (arr[first1] <= arr[first2])){
            tempArr[index - first] = arr[first1++];
            index++;
        }else{
            tempArr[index - first] = arr[first2++];
            index++;
        }
    }

    while ((++comparision) && (first1 <= last1)){ // Finish the first subarray, if necessary
        tempArr[index - first] = arr[first1++];
        index++;
    }
    while ( (++comparision) && (first2 <= last2)){ // Finish the second subarray, if necessary
        tempArr[index - first] = arr[first2++];
        // Copy the result back into the original array
        index++;
    }
    for (index = first; (++comparision) && (index <= last); ++index){
        arr[index] = tempArr[index - first];
    }
    delete[]tempArr; // Free the memory used by tempArr
}

void mergeSortComparision(int *arr, int first, int last, int &comparision){
    
    if (++comparision && first < last) {
        int mid = (first + last) / 2; // Index of midpoint
        mergeSortComparision(arr, first, mid, comparision); // Sort left half
        mergeSortComparision(arr, mid + 1, last, comparision); // Sort right half
        mergeComparision(arr, first, mid, last, comparision); // Merge the two halves
    }
}
//calculate the time of merge sort

void mergeTime(int *arr, int first, int mid, int last){

    int first1 = first, last1 = mid; 
    int first2 = mid + 1, last2 = last; 

    int *tempArr = new int[last - first + 1]; 
    int index = first1; 

    while ((first1 <= last1) && (first2 <= last2)) {

        if (arr[first1] <= arr[first2]){
            tempArr[index - first] = arr[first1++];
            index++;
        }else{
            tempArr[index - first] = arr[first2++];
            index++;
        }
    }

    while (first1 <= last1){ 
        tempArr[index - first] = arr[first1++];
        index++;
    }

    while (first2 <= last2){ 
        tempArr[index - first] = arr[first2++];
        index++;
    }
    for (index = first; index <= last; ++index){
        arr[index] = tempArr[index - first];
    }
    delete[]tempArr; 
}

void mergeSortTime(int *arr, int first, int last){
    
    if (first < last) {
        int mid = (first + last) / 2; 
        mergeSortTime(arr, first, mid); 
        mergeSortTime(arr, mid + 1, last); 
        mergeTime(arr, first, mid, last); 
    }
}

void calTimeMergeSort(int *arr, int n){
    clock_t begin = clock(); 
    mergeSortTime(arr, 0, n-1);
    
    clock_t end = clock();
    cout<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
}
