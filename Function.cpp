#include "Header.h"
#include "bubbleSort.h"
#include "countingSort.h"
#include "flashSort.h"
#include "heapSort.h"
#include "insertionSort.h"
#include "Merge_Sort.h"
#include "quickSort.h"
#include "RadixSort.h"
#include "Selection_Sort.h"
#include "Shaker_Sort.h"
#include "ShellSort.h"

using namespace std;

template <class T>
void HoanVi(T& a, T& b)
{
    T x = a;
    a = b;
    b = x;
}
// Function to create random data
void GenerateRandomData(int* a, int n)
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % n;
    }
}

// Function to create increasing data
void GenerateSortedData(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
}

// Function to create decreasing data
void GenerateReverseData(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = n - 1 - i;
    }
}

// Function to create almost increasing data
void GenerateNearlySortedData(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int r1 = rand() % n;
        int r2 = rand() % n;
        HoanVi(a[r1], a[r2]);
    }
}

void GenerateData(int* a, int n, int dataType)
{
    switch (dataType)
    {
    case 0:	// random
        GenerateRandomData(a, n);
        break;
    case 1:	// increasing
        GenerateSortedData(a, n);
        break;
    case 2:	// decreasing
        GenerateReverseData(a, n);
        break;
    case 3:	// almost increasing
        GenerateNearlySortedData(a, n);
        break;
    default:
        printf("Error: unknown data type!\n");
    }
}
void CreateFile()
{
    ofstream fout("input.txt");
    if (!fout.is_open())
    {
        cerr << "Failed to open file." << endl;
        return;
    }

    int n;
    cout << "Input n: ";
    cin >> n;
    fout << n << endl;

    int* a = new int[n];

    int dataType;
    cout << "0. RandomData" << endl
        << "1. SortedData" << endl
        << "2. ReverseData" << endl
        << "3. NearlySortedData" << endl;
    cout << "Input data type: ";
    cin >> dataType;

    GenerateData(a, n, dataType);

    for (int i = 0; i < n; i++)
        fout << a[i] << " ";

    fout.close();

    delete[] a;
}


void showMenu()
{
    //Create data
    cout << "Do you have data yet? (1/0)" << endl;
    bool ans;
    cin >> ans;
    if (!ans)
        CreateFile();
    int n;

    ifstream fin("input.txt");
    if (!fin.is_open())
    {
        cerr << "Failed to open file." << endl;
        return;
    }

    fin >> n;

    int* a = new int[n];
    for (int i = 0; i < n; i++)
        fin >> a[i];

    fin.close();
    long long cnt_comp = 0;
    int choice;

    cout << "=== TIME RUNNING & COMPARISONS ===" << endl;
    cout << "1. Radix Sort" << endl;
    cout << "2. Shell Sort" << endl;
    cout << "3. Bubble Sort" << endl
        << "4. Counting Sort" << endl
        << "5. Flash Sort" << endl
        << "6. Heap Sort" << endl
        << "7. Insertion Sort" << endl
        << "8. Merge Sort" << endl
        << "9. Quick Sort" << endl
        << "10. Selection Sort" << endl
        << "11. Shaker Sort" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {

        cout << "Running time: " << RadixSortRuntime(a, n) << endl;

        Com_RadixSort(a, n, cnt_comp);
        cout << "Comparison: " << cnt_comp << endl;

        delete[] a;
    }
    else if (choice == 2)
    {
        cout << "Running time: " << ShellSortRuntime(a, n) << endl;

        Com_ShellSort(a, n, cnt_comp);
        cout << "Comparison: " << cnt_comp << endl;

        delete[] a;
    }
    else if (choice == 3)
    {
        cout << "Running time: " << bubbleSortRuntime(a, n) << endl;

        bubbleSort(a, n, cnt_comp);
        cout << "Comparison: " << cnt_comp << endl;

        delete[] a;
    }
    else if (choice == 4)
    {
        cout << "Running time: " << countingSortRuntime(a, n) << endl;

        countingSort(a, n, cnt_comp);
        cout << "Comparison: " << cnt_comp << endl;

        delete[] a;
    }
    else if (choice == 5)
    {
        cout << "Running time: " << flashSortRuntime(a, n) << endl;

        flashSortComparison(a, n, cnt_comp);
        cout << "Comparison: " << cnt_comp << endl;

        delete[] a;
    }
    else if (choice == 6)
    {
        cout << "Running time: " << heapSortRuntime(a, n) << endl;

        heapSortComparison(a, n, cnt_comp);
        cout << "Comparison: " << cnt_comp << endl;

        delete[] a;
    }
    else if (choice == 7)
    {
        cout << "Running time: " << insertionSortRuntime(a, n) << endl;

        insertionSort(a, n, cnt_comp);
        cout << "Comparison: " << cnt_comp << endl;

        delete[] a;
    }
    else if (choice == 8)
    {
        cout << "Running time: " << mergeSortRuntime(a, n) << endl;

        calComparisionMergeSort(a, n, cnt_comp);
        cout << "Comparison: " << cnt_comp << endl;

        delete[] a;
    }
    else if (choice == 9)
    {

    }
    else if (choice == 10)
    {
        cout << "Running time: " << calTimeSelectionSort(a, n) << endl;

        selecionSortComparision(a, n, cnt_comp);
        cout << "Comparison: " << cnt_comp << endl;

        delete[] a;
    }
    else if (choice == 11)
    {
        cout << "Running time: " << calTimeShakerSort(a, n) << endl;

        shakerSortComparision(a, n, cnt_comp);
        cout << "Comparison: " << cnt_comp << endl;

        delete[] a;
    }
}
