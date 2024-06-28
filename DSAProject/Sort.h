#pragma once
#include <iostream>

using namespace std;

typedef long long ll;

int binarySearch(int* arr, int item, int low, int high, long long& comparisons);

// Insertion Sort
void binaryInsertionSort(int* arr, int size, long long& comparisons);

// Selection Sort
void selectionSort(int*, int, ll&);

// Bubble Sort
void bubbleSort(int*, int, ll&);

// Shaker Sort
void shakerSort(int*, int, ll&);

// Shell Sort
void shellSort(int*, int, ll&);

// Heap Sort
void Heapify(int*, int, int , ll&);

void heapSort(int*, int, ll&);

// Merge Sort
void Merge(int*, int, int, int, ll&);

void mergeSort(int*, int, int, ll&);

void WrappedMergeSort(int* a, int n, ll& comparison_count);

// Quick Sort
int Partition(int*, int, int, ll&);

void quickSort(int*, int, int, ll&);

void WrappedQuickSort(int* a, int n, ll& comparison_count);

// Counting Sort
void countingSort(int*, int, ll&);

// Radix Sort
int getMax(int*, int, ll&);

void countSort(int*, int, int);

void radixSort(int*, int, ll&);

// Flash Sort
void flashSort(int*, int, ll&);

