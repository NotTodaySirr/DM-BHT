#include "Command.h"


void command1(const int argc,const char* argv[])
{
	int size;
	long long comparisons = 0;
	long double time = 0;
	int* a;

	string algorithm = argv[2];
	string inputPath = argv[3];
	string outputParameter = argv[4];

	//read input file 
	readFile(inputPath, size, a);
	cout << "------------Command 1------------" << endl;

	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm: " << chuanHoaAlgorithm(algorithm) << endl;
	cout << "Input file: " << argv[3] << endl;
	cout << "Input size: " << size << endl;
	cout << "---------------------------------" << endl;

	//measure time and comparisons
	readAlgorithm(algorithm, a, size, time, comparisons);

	if (comparisons != -1) {
		//read output parameter and print result
		readOutputParameter(outputParameter, time, comparisons);
	}
	else {
		cout << "Invalid algorithm" << endl;
	}

	delete[] a;
}

void command2(int argc,const char* argv[])
{
	long long comparisons = 0;
	ld time = 0;
	int* a;

	string algorithm = argv[2];
	int size = convertStringToInt(argv[3]);
	string inputOrder = argv[4];
	
	cout << "------------Command 2------------" << endl;

	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm: " << chuanHoaAlgorithm(algorithm) << endl;
	cout << "Input size: " << argv[3] << endl;
	cout << "Input order: " << chuanhoaDataOrder(inputOrder) << endl;
	cout << "---------------------------------" << endl;

	//generate data
	a = new int[size];
	GenerateData(a, size, inputOrder);

	//measure time and comparisons
	readAlgorithm(algorithm, a, size, time, comparisons);

	if (comparisons != -1) {
		//read output parameter and print result
		readOutputParameter(argv[5], time, comparisons);
	}
	else {
		cout << "Invalid algorithm" << endl;
	}
	
	delete[] a;
}


void command5(const int argc,const char* argv[]) {


	const char* mode = argv[1];
	const string alg1 = argv[2];
	const string alg2 = argv[3];
	int inputSize = atoi(argv[4]);
	const string inputOrder = argv[5];



	// Generate input data
	int* data1 = new int[inputSize];
	GenerateData(data1, inputSize, inputOrder);

	//// Write input data to file
	//input_to_file("input.txt", data1, inputSize);

	// Copy data for 2nd algorithm
	int* data2 = new int[inputSize];
	memcpy(data2, data1, inputSize * sizeof(int));

	long long comparison_count1 = 0;
	long long comparison_count2 = 0;
	long double running_time1 = 0.0;
	long double running_time2 = 0.0;

	// Measure time for 1st algorithm
	readAlgorithm(alg1, data1, inputSize, running_time1, comparison_count1);
	

	// Measure time for 2nd algorithm
	readAlgorithm(alg2, data2, inputSize, running_time2, comparison_count2);
	

	// Output
	cout << alg1 << "|" << alg2 << endl;
	cout << "Running time: " << running_time1 << "ms | " << running_time2 << "ms. " << endl;
	cout << "Comparisons: " << comparison_count1 << " | " << comparison_count2 << endl;

	delete[] data1;
	delete[] data2;

}

void command4(const int argc,const char* argv[])
{
	long long comparisons[2];
	ld time[2];
	int* a;
	int size = 0;

	string algorithms[2];
	algorithms[0] = argv[2];
	algorithms[1] = argv[3];
	string inputPath = argv[4];
	// Checking the input

	// File processing
	readFile(inputPath, size, a);

	cout << "------------Command 4------------" << endl;

	cout << "COMPARE MODE" << endl;
	cout << "Algorithm: " << argv[2] << " | " << argv[3] << endl;
	cout << "Input file: " << argv[4] << endl;
	cout << "Input size: " << size << endl;
	cout << "---------------------------------" << endl;

	for (int i = 0;i <= 1;i++)
	{
		// Clone a temp array from original file's array
		int* tempArray = new int[size];
		for (int j = 0;j < size;j++)
		{
			tempArray[j] = a[j];
		}

		readAlgorithm(algorithms[i], tempArray, size, time[i], comparisons[i]);

		delete[] tempArray;
	}
	delete[] a;

	// Print result
	cout << "Running time: " << time[0] << " | " << time[1] << endl;
	cout << "Comparisons: " << comparisons[0] << " | " << comparisons[1] << endl;
}