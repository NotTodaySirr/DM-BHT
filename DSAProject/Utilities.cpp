#include "Utilities.h"


//measure time and comparisons
long long measureSortTime(void (*sortFunc)(int*, int, long long&), int* a, int size,ll& comparisons) {
    auto start = chrono::high_resolution_clock::now();
    comparisons = 0;
    sortFunc(a, size, comparisons);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duration = end - start;
    return duration.count();
}



int convertStringToInt(string s)
{
	int res = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] < '0' || s[i] > '9') return 0;
		res = res * 10 + (s[i] - '0');
	}
	return res;
}

int readACommand(int argc, char* argv[])
{
    if (argc == 6) return 2;
    else if (argc == 5)
    {
        if (convertStringToInt(argv[3])) return 3;
        else return 1;
    }
    return -1;
}

int readCCommand(int argc, char* argv[])
{
    if (argc == 5) return 4;
    else if (argc == 6) return 5;

    return -1;
}

void readFile(string path, int& size, int*& arr)
{
    ifstream fin(path);
    if (!fin.is_open())
    {
		cout << "Cannot open file\n";
		return;
	}

    fin >> size;

    arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        fin >> arr[i];
    }
}



int readDataType(const string s)
{
    if (s == "-rand") return 0;
	else if (s == "-sorted") return 1;
	else if (s == "-rev") return 2;
	else if (s == "-nsorted") return 3;
	else return -1;
}

void readOutputParameter(const string s, long long time, long long comparisons)
{
    if (s == "-both")
    {
        cout << "Running time: " << time << " ms" << endl;
        cout << "Comparisons: " << comparisons << endl;
    }
    else if (s == "-time")
    {
        cout << "Running time: " << time << " ms" << endl;
    }
    else if (s == "-comp")
    {
        cout << "Comparisons: " << comparisons << endl;
    }
    else
    {
        cout << "Invalid output parameter" << endl;
    }
}

void readAlgorithm(const string algorithm, int* a, int size, ll& time, ll& comparisons)
{
	if (algorithm == "selection-sort")
	{
		time = measureSortTime(selectionSort, a, size, comparisons);
	}
	else if (algorithm == "binary-insertion-sort")
	{
		time = measureSortTime(binaryInsertionSort, a, size, comparisons);
	}
	else if (algorithm == "bubble-sort")
	{
		time = measureSortTime(bubbleSort, a, size, comparisons);
	}
	else if (algorithm == "quick-sort")
	{
		time = measureSortTime(WrappedQuickSort, a, size, comparisons);
	}
	else if (algorithm == "merge-sort")
	{
		time = measureSortTime(WrappedMergeSort, a, size, comparisons);
	}
	else if (algorithm == "heap-sort")
	{
		time = measureSortTime(heapSort, a, size, comparisons);
	}
	else if (algorithm == "radix-sort")
	{
		time = measureSortTime(radixSort, a, size, comparisons);
	}
	else if (algorithm == "flash-sort")
	{
		time = measureSortTime(flashSort, a, size, comparisons);
	}
	else if (algorithm == "shell-sort")
	{
		time = measureSortTime(shellSort, a, size, comparisons);
	}
	else if (algorithm == "counting-sort")
	{
		time = measureSortTime(countingSort, a, size, comparisons);
	}
	else if (algorithm == "shaker-sort")
	{
		time = measureSortTime(shakerSort, a, size, comparisons);
	}
	else
	{
		comparisons = -1;
		cout << "Invalid algorithm" << endl;
		return;
	}
}