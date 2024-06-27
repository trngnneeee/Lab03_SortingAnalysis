#include "quickSort.h"

// int numCmpLomuto = 0;

int partition1(int a[], int l, int r, int &numCmpLomuto){
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
    int p = partition1(a, l, r, numCmpLomuto);
    quickSort1(a, l, p - 1, numCmpLomuto);
    quickSort1(a, p + 1, r, numCmpLomuto);
  }
}

int partitionRunTime(int a[], int l, int r)
{
  int x = a[r];
  int j = l - 1;
  for (int i = l; i < r; i++)
  {
    if (a[i] <= x)
    {
      j++;
      swap(a[i], a[j]);
    }
  }
  j++;
  swap(a[j], a[r]);
  return j;
}

void quickSortRunTime(int a[], int l, int r)
{
  static bool isFirstCall = true; 
  auto start = high_resolution_clock::now();

  if (l < r)
  {
    int p = partitionRunTime(a, l, r);
    quickSortRunTime(a, l, p - 1);
    quickSortRunTime(a, p + 1, r);
  }

  if (isFirstCall)
  {
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Running time: " << duration.count() << endl;
    isFirstCall = false;
  }
}
