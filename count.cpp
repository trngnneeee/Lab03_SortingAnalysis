#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

using ll = long long;

// Insertion sort
void insertionSort(int* a, int n, int &numCmp) {
    numCmp = 0;
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while ((++numCmp && j >= 0) && (++numCmp && a[j] > key)) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// Counting sort
void countingSort(int *arr, int n, int &numCmp){
    numCmp = 0;

    int maxVal = *max_element(arr, arr + n);
    numCmp += n;

    int* count = new int[maxVal + 1]();

    for (int i = 0; ++numCmp && i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; ++numCmp && i <= maxVal; i++) {
        count[i] += count[i - 1];
    }

    int* output = new int[n];

    for (int i = n - 1; ++numCmp && i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; ++numCmp && i < n; i++) {
        arr[i] = output[i];
    }
    delete[] count;
}

// Quick sort
// Ver1. Lomuto's Partition Scheme

int numCmpLomuto = 0;

int partition1(int a[], int l, int r){
  int x = a[r];
  int j = l - 1;
  for (int i = l; ++numCmpLomuto && i < r; i++)
  {
    if (++numCmpLomuto && a[i] <= x)
    {
        j++;
        swap(a[i], a[j]);
    }
  }
  j++;
  swap(a[j], a[r]);
  return j;
}

void quickSort1(int a[], int l, int r){
  if (++numCmpLomuto && l < r)
  {
    int p = partition1(a, l, r);
    quickSort1(a, l, p - 1);
    quickSort1(a, p + 1, r);
  }
}

// Ver2. Hoare Partition Scheme

int numCmpHoare = 0;

int partition2(int a[], int l, int r){
  int x = a[l];
  int i = l - 1, j = r + 1;
  while (++numCmpHoare && true)
  {
    do
    {
      j--;
    } while (++numCmpHoare && a[j] > x);
    do
    {
      i++;
    } while (++numCmpHoare && a[i] < x);
    if (++numCmpHoare && i < j)
    {
      swap(a[i], a[j]);
    }
    else
    {
      return j;
    }
  }
}

void quickSort2(int a[], int l, int r){
  if (++numCmpHoare && l < r)
  {
    int p = partition2(a, l, r);
    quickSort2(a, l, p);
    quickSort2(a, p + 1, r);
  }
}

int main(){
    int* a = new int[5];
    a[0] = 5;
    a[1] = 4;
    a[2] = 3;
    a[3] = 2;
    a[4] = 1;
    int n = 5;
    int numCmp = 0;
    quickSort2(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons: " << numCmpHoare << endl;
    return 0;
}