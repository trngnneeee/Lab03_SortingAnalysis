#include "Merge_Sort.h"

void mergeComparision(int *arr, int first, int mid, int last, int &comparision)
{

    int first1 = first, last1 = mid;
    int first2 = mid + 1, last2 = last;

    int *tempArr = new int[last - first + 1];
    int index = first1;
    while ((++comparision && first1 <= last1) && (++comparision && first2 <= last2))
    {
        if ((++comparision) && (arr[first1] <= arr[first2]))
        {
            tempArr[index - first] = arr[first1++];
            index++;
        }
        else
        {
            tempArr[index - first] = arr[first2++];
            index++;
        }
    }

    while ((++comparision) && (first1 <= last1))
    {
        tempArr[index - first] = arr[first1++];
        index++;
    }
    while ((++comparision) && (first2 <= last2))
    {
        tempArr[index - first] = arr[first2++];
        index++;
    }
    for (index = first; (++comparision) && (index <= last); ++index)
    {
        arr[index] = tempArr[index - first];
    }
    delete[] tempArr;
}

void mergeSortComparision(int *arr, int first, int last, int &comparision)
{

    if (++comparision && first < last)
    {
        int mid = (first + last) / 2;
        mergeSortComparision(arr, first, mid, comparision);
        mergeSortComparision(arr, mid + 1, last, comparision);
        mergeComparision(arr, first, mid, last, comparision);
    }
}
void calComparisionMergeSort(int *arr, int n, int &comparision)
{
    comparision = 0;
    mergeSortComparision(arr, 0, n - 1, comparision);
}

void mergeTime(int *arr, int first, int mid, int last)
{

    int first1 = first, last1 = mid;
    int first2 = mid + 1, last2 = last;

    int *tempArr = new int[last - first + 1];
    int index = first1;

    while ((first1 <= last1) && (first2 <= last2))
    {

        if (arr[first1] <= arr[first2])
        {
            tempArr[index - first] = arr[first1++];
            index++;
        }
        else
        {
            tempArr[index - first] = arr[first2++];
            index++;
        }
    }

    while (first1 <= last1)
    {
        tempArr[index - first] = arr[first1++];
        index++;
    }

    while (first2 <= last2)
    {
        tempArr[index - first] = arr[first2++];
        index++;
    }
    for (index = first; index <= last; ++index)
    {
        arr[index] = tempArr[index - first];
    }
    delete[] tempArr;
}

void mergeSortTime(int *arr, int first, int last)
{

    if (first < last)
    {
        int mid = (first + last) / 2;
        mergeSortTime(arr, first, mid);
        mergeSortTime(arr, mid + 1, last);
        mergeTime(arr, first, mid, last);
    }
}

void mergeSortRuntime(int *arr, int n)
{
    auto start = high_resolution_clock::now();
    mergeSortTime(arr, 0, n - 1);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Running time: " << duration.count() << endl;
}
