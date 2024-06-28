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

using namespace std;

long long measureSortTime(void (*sortFunc)(int*, int, long long&), int* a, int size, ll& comparisons);

int convertStringToInt(string s);
int readACommand(int argc, char* argv[]);
int readCCommand(int argc, char* argv[]);
void readFile(string path, int& size, int*& arr);
void readOutputParameter(const string s, long long time, long long comparisons);
void readAlgorithm(const string algorithm, int* a, int size, ll& time, ll& comparisons);