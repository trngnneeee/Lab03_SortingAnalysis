#include "commandLine.h"

int main(int argc, char *argv[])
{
    if (argc == 5)
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
            // command 1
            if (!isNumeric)
            {
                cout << "Input file: " << argv[3] << endl;
                num = readFile(n, argv[3]);
                cout << "Input size: " << n << endl;
                cout << "------------------------------------\n";
                runSort(num, n, argv[2], argv[4]);
                writeFile(num, n, "output.txt");
                delete[] num;
            }
            // Command 3
            else if (isNumeric)
            {
                n = atoi(argv[3]);
                num = new int[n];
                cout << endl;
                cout << "Input size: " << n << "\n";
                cout << "\n";
                cout << "Input order: Randomize\n";
                cout << "--------------------------\n";
                GenerateRandomData(num, n);
                writeFile(num, n, "input1.txt");
                runSort(num, n, argv[2], argv[4]);

                cout << "\n";
                cout << "Input order: Nearly Sorted\n";
                cout << "----------------------------\n";
                GenerateNearlySortedData(num, n);
                writeFile(num, n, "input2.txt");
                runSort(num, n, argv[2], argv[4]);

                cout << "\n";
                cout << "Input order: Sorted\n";
                cout << "----------------------------\n";
                GenerateSortedData(num, n);
                writeFile(num, n, "input3.txt");
                runSort(num, n, argv[2], argv[4]);

                cout << "\n";
                cout << "Input order: Reverse\n";
                cout << "----------------------------\n";
                GenerateReverseData(num, n);
                writeFile(num, n, "input4.txt");
                runSort(num, n, argv[2], argv[4]);
                delete[] num;
            }
        }
        else if (strcmp(argv[1], "-c") == 0)
        {
            //[Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]
            cout << "COMPARE NODE\n";
            cout << "Algorithm: " << argv[2] << " | " << argv[3] << "\n";
            cout << "Input file: " << argv[4] << "\n";
            int n = 0;
            int *num = readFile(n, argv[4]);
            cout << "Input size: " << n << "\n";
            cout << "-------------------------------\n";
            cout << "Running time: " << runSort2(num, n, argv[2], (char *)"-time") << "|" << runSort2(num, n, argv[3], (char *)"-time") << endl;
            cout << "Comparisions: " << (int)runSort2(num, n, argv[2], (char *)"-comp") << "|" << (int)runSort2(num, n, argv[3], (char *)"-comp") << endl;
            delete[] num;
        }
        else
            cout << "Not Found!\n";
    }
    else if (argc == 6)
    {
        // Prototype: [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]
        if (strcmp(argv[1], "-a") == 0)
        {
            cout << "ALGORITHM MODE" << endl;
            cout << "Algorithm: " << argv[2] << endl;
            int n = atoi(argv[3]);
            int *num = new int[n];
            cout << "Input size: " << n << "\n";
            if (strcmp(argv[4], "-rand") == 0)
            {
                cout << "Input order: randomize data\n";
                cout << "--------------------------\n";
                GenerateRandomData(num, n);
                writeFile(num, n, "input.txt");
                runSort(num, n, argv[2], argv[5]);
                writeFile(num, n, "output.txt");
            }
            else if (strcmp(argv[4], "-nsorted") == 0)
            {
                cout << "Input order: nearly sorted data\n";
                cout << "----------------------------\n";
                GenerateNearlySortedData(num, n);
                writeFile(num, n, "input.txt");
                runSort(num, n, argv[2], argv[5]);
                writeFile(num, n, "output.txt");
            }
            else if (strcmp(argv[4], "-sorted") == 0)
            {
                cout << "Input order: sorted data\n";
                cout << "----------------------------\n";
                GenerateSortedData(num, n);
                writeFile(num, n, "input.txt");
                runSort(num, n, argv[2], argv[5]);
                writeFile(num, n, "output.txt");
            }
            else if (strcmp(argv[4], "-rev") == 0)
            {
                cout << "Input order: reverse sorted data\n";
                cout << "----------------------------\n";
                GenerateReverseData(num, n);
                writeFile(num, n, "input.txt");
                runSort(num, n, argv[2], argv[5]);
                writeFile(num, n, "output.txt");
            }
            delete[] num;
        }
        else if (strcmp(argv[1], "-c") == 0)
        {
            // a.exe -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]
            cout << "COMPARE MODE \n";
            cout << "Algorithm: " << argv[2] << " | " << argv[3] << "\n";
            cout << "Input size: " << argv[4] << "\n";
            int n = stoi(argv[4]);
            int *num = new int[n];
            if (strcmp(argv[5], "-rand") == 0)
            {
                cout << "Input order: randomize data\n";
                cout << "--------------------------\n";
                GenerateRandomData(num, n);
                writeFile(num, n, "input.txt");
                cout << "Running time: " << runSort2(num, n, argv[2], (char *)"-time") << " | " << runSort2(num, n, argv[3], (char *)"-time") << endl;
                cout << "Comparisions: " << (int)runSort2(num, n, argv[2], (char *)"-comp") << " | " << (int)runSort2(num, n, argv[3], (char *)"-comp") << endl;
                // writeFile(num, n, "output.txt");
            }
            else if (strcmp(argv[5], "-nsorted") == 0)
            {
                cout << "Input order: nearly sorted data\n";
                cout << "----------------------------\n";
                GenerateNearlySortedData(num, n);
                writeFile(num, n, "input.txt");
                cout << "Running time: " << runSort2(num, n, argv[2], (char *)"-time") << " | " << runSort2(num, n, argv[3], (char *)"-time") << endl;
                cout << "Comparisions: " << (int)runSort2(num, n, argv[2], (char *)"-comp") << " | " << (int)runSort2(num, n, argv[3], (char *)"-comp") << endl;
                // writeFile(num, n, "output.txt");
            }
            else if (strcmp(argv[5], "-sorted") == 0)
            {
                cout << "Input order: sorted data\n";
                cout << "----------------------------\n";
                GenerateSortedData(num, n);
                writeFile(num, n, "input.txt");
                cout << "Running time: " << runSort2(num, n, argv[2], (char *)"-time") << " | " << runSort2(num, n, argv[3], (char *)"-time") << endl;
                cout << "Comparisions: " << (int)runSort2(num, n, argv[2], (char *)"-comp") << " | " << (int)runSort2(num, n, argv[3], (char *)"-comp") << endl;
                // writeFile(num, n, "output.txt");
            }
            else if (strcmp(argv[5], "-rev") == 0)
            {
                cout << "Input order: reverse sorted data\n";
                cout << "----------------------------\n";
                GenerateReverseData(num, n);
                writeFile(num, n, "input.txt");
                cout << "Running time: " << runSort2(num, n, argv[2], (char *)"-time") << " | " << runSort2(num, n, argv[3], (char *)"-time") << endl;
                cout << "Comparisions: " << (int)runSort2(num, n, argv[2], (char *)"-comp") << " | " << (int)runSort2(num, n, argv[3], (char *)"-comp") << endl;
                // writeFile(num, n, "output.txt");
            }
            delete[] num;
        }
    }
    return 0;
}
