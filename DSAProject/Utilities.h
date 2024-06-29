#pragma once
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <random>
#include <sstream>
#include <string>
#include <fstream>
#include "Sort.h"

typedef long long ll;
typedef long double ld;

using namespace std;

long double measureSortTime(void (*sortFunc)(int*, int, long long&), int* a, int size, ll& comparisons);

int convertStringToInt(string s);


				//read command	
int readACommand(const int argc,const char* argv[]);

int readCCommand(const int argc,const char* argv[]);

void readFile(string path, int& size, int*& arr);

				//valid checking

bool checkValidOutput(const string s);

bool checkValidInputOrder(const string s);

bool checkValidAlgorithm(const string& algorithm);

				//measure time, comparisons and print result
void readOutputParameter(const string s, long double& time, long long& comparisons);

void MeasureAlgorithm(const string algorithm, int* a,const int size, ld& time, ll& comparisons);



				//standardize string
string standardizeAlgorithm(const string s);

string standardizeDataOrder(const string s);

		

				//write to file
void writetoFile(string path, int* a, int size);