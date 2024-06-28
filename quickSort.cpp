#include "quickSort.h"

int partitionRunTime(int *arr,int low,int high)
{  
  int pivot=arr[high];
  int i=(low-1);
  
  for(int j=low;j<=high-1;j++)
  {
    if(arr[j]<pivot)
    {
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[high]);
  return (i+1);
}

void quickSortRunTime(int* arr, int low, int high) {
  if (low < high) {
    int pi = partitionRunTime(arr, low, high);
    quickSortRunTime(arr, low, pi - 1);
    quickSortRunTime(arr, pi + 1, high);
  }
}

int partition(int *arr,int low,int high, int &numCmp)
{  
  int pivot=arr[high];
  int i=(low-1);
  
  for(int j=low;++numCmp && j<=high-1;j++)
  {
    if(++numCmp && arr[j]<pivot)
    {
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[high]);
  return (i+1);
}

void quickSort(int* arr, int low, int high, int &numCmp) {
  if (low < high) {
    int pi = partition(arr, low, high, numCmp);
    quickSort(arr, low, pi - 1, numCmp);
    quickSort(arr, pi + 1, high, numCmp);
  }
}

int main(){
  int n = 6;
  int* a = new int[n]{12, 11, 13, 5, 6, 7};
  // auto start = high_resolution_clock::now();
  // quickSortRunTime(a, 0, n - 1);
  // auto stop = high_resolution_clock::now();
  // auto duration = duration_cast<milliseconds>(stop - start);
  // cout << "Quick Sort Runtime: " << (double)duration.count() << " milliseconds" << endl;

  int numCmp = 0;
  quickSort(a, 0, n - 1, numCmp);
  cout << "Number of comparisons: " << numCmp << endl;
  return 0;
}