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
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;

template <class T>
void HoanVi(T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int) time(NULL));
	for (int i = 0; i < 10; i ++)
	{
		int r1 = rand()%n;
		int r2 = rand()%n;
		HoanVi(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(a, n);
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(a, n);
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}

int *readFile(int &n, char *filename);
void runSort(int *arr, int n, char *algorithm, char *mode);

int main(int argc, char *argv[])
{
    if (argc == 4)
    {
        if (strcmp(argv[1], "-a") == 0)
        {
            cout << "ALGORITHM MODE" << endl;
            cout << "Algorithm: " << argv[2] << endl;
            bool isNumeric = true;
            for (int i = 0; argv[3][i] != '\0'; i++)
            {
                if (!isdigit(argv[3][i]))
                {
                    isNumeric = false;
                    break;
                }
            }
            int n;
            int *num;
            if(!isNumeric){
                cout << "Input file: " << argv[3] << endl;
                num = readFile(n, argv[3]);
                cout << "Input size: " << n << endl;
            }
        }
    }
    return 0;
}

int *readFile(int &n, char *filename){
    ifstream fin(filename);
    if(!fin.is_open()){
        cout << "Cannot open file " << filename << endl;
        return NULL;
    }

    fin >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++){
        fin >> a[i];
    }

    fin.close();
    return a;
}

void runSort(int *arr, int n, char *algorithm, char *mode){
    if(strcmp(algorithm, "bubble-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            bubbleSortRuntime(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison;
            bubbleSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            bubbleSortRuntime(arr, n);
            int count_comparison;
            bubbleSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }

}