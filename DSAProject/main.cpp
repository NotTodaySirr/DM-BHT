#include "Utilities.h"
#include "Command.h"



using namespace std;

// Time Measurement
long double measureTime(const char* sortFunction, int* a, int n, ll& comp) {
	using namespace chrono;
	auto start = high_resolution_clock::now(); // Get the current time before sorting

	// Determine which sorting function to call based on sortFunction string
	if (strcmp(sortFunction, "selection-sort") == 0) {
		selectionSort(a, n, comp);
	}
	else if (strcmp(sortFunction, "insertion-sort") == 0) {
		binaryInsertionSort(a, n, comp);
	}
	else if (strcmp(sortFunction, "bubble-sort") == 0) {
		bubbleSort(a, n, comp);
	}
	else if (strcmp(sortFunction, "shaker-sort") == 0) {
		shakerSort(a, n, comp);
	}
	else if (strcmp(sortFunction, "shell-sort") == 0) {
		shellSort(a, n, comp);
	}
	else if (strcmp(sortFunction, "heap-sort") == 0) {
		heapSort(a, n, comp);
	}
	else if (strcmp(sortFunction, "merge-sort") == 0) {
		WrappedMergeSort(a, n, comp); // Merge sort requires additional parameters
	}
	else if (strcmp(sortFunction, "quick-sort") == 0) {
		WrappedQuickSort(a, n, comp); // Quick sort requires additional parameters
	}
	else if (strcmp(sortFunction, "counting-sort") == 0) {
		countingSort(a, n, comp);
	}
	else if (strcmp(sortFunction, "radix-sort") == 0) {
		radixSort(a, n, comp);
	}
	else if (strcmp(sortFunction, "flash-sort") == 0) {
		flashSort(a, n, comp);
	}
	else {
		throw runtime_error("Sorting algorithm not found");
	}

	auto stop = high_resolution_clock::now(); // Get the current time after sorting
	auto duration = duration_cast<milliseconds>(stop - start); // Calculate the duration in milliseconds

	return duration.count(); // Return the duration as a double
}

int main(const int argc,const char* argv[]) {

	if (argc < 2) {
		  cout << "Invalid arguments" << endl;
		  return 1;
	}
	
	if (!strcmp(argv[1], "-a"))
	{
		int cmnd = readACommand(argc, argv);
		switch (cmnd)
		{
		case 1 : 
			command1(argc, argv);
			break;

		case 2:
			command2(argc, argv);
			break;

		case 3:
			//command 3 goes here
			break;
		}
	
	}
	else if (!strcmp(argv[1], "-c"))
	{
		//code run here
		int cmnd = readCCommand(argc, argv);
		switch (cmnd)
		{

			case 4:
				command4(argc, argv);	
				break;

			case 5:
				command5(argc, argv);
				break;
		}
	}


	else cout << "can't regconize command " << endl;
	
	//int n = 10000;
	//int* a = new int[n];

	//GenerateData(a, n, "-rand");
	//ll comp = 0;

	//long double time2 = measureSortTime(selectionSort, a, n, comp);
	//ld time3 = measureTime("selection-sort", a, n, comp);
	//cout << time2 << " - " << time3 << endl;

	//for (int i = 0; i < n; i++) {
	//	cout << a[i] << " ";
	//}
	//cout << endl << comp1;

//	delete[] a;
    return 0;
}