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
int readACommand(const int argc,const char* argv[]);
int readCCommand(const int argc,const char* argv[]);
void readFile(string path, int& size, int*& arr);
void readOutputParameter(const string s, long double& time, long long& comparisons);
void readAlgorithm(const string algorithm, int* a,const int size, ld& time, ll& comparisons);
string chuanHoaAlgorithm(const string s);
string chuanhoaDataOrder(const string s);