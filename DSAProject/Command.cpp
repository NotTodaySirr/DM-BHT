#include "Command.h"


void command1(int argc, char* argv[])
{
	int size;
	long long time = 0, comparisons = 0;
	int* a;

	string algorithm = argv[2];
	string inputPath = argv[3];
	string outputParameter = argv[4];

	//read input file 
	readFile(inputPath, size, a);
	cout << "------------Command 1------------" << endl;

	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm: " << algorithm << endl;
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

void command2(int argc, char* argv[])
{
	long long time = 0, comparisons = 0;
	int* a;

	string algorithm = argv[2];
	int size = convertStringToInt(argv[3]);
	string inputOrder = argv[4];
	
	cout << "------------Command 2------------" << endl;

	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm: " << algorithm << endl;
	cout << "Input size: " << argv[3] << endl;
	cout << "Input order: " << inputOrder << endl;
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