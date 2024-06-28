#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include "Sort.h"


int binarySearch(int* arr, int item, int low, int high, long long& comparisons) {
	comparisons = 0;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		comparisons++;
		if (arr[mid] == item) {
			return mid + 1;
		}
		else if (arr[mid] < item) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return low;
}

// Binary Insertion Sort Implementation
void binaryInsertionSort(int* arr, int size, long long& comparisons) {
	for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j = i - 1;

		// Find location where key should be inserted
		int loc = binarySearch(arr, key, 0, j, comparisons);

		// Move all elements after location to create space
		while (j >= loc) {
			comparisons++;
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

// Selection Sort
void selectionSort(int* a, int n, ll& comparison_count) {
	comparison_count = 0;
	for (int i = 0; i < n; i++) { // Loops through the array.
		int min_index = i; // Assumes the current index is the minimum.
		for (int j = 0; j < n; j++) { // Finds the minimum element in the unsorted part of the array.
			comparison_count++;
			if (a[j] < a[min_index]) { // Updates the minimum index if a smaller element is found.
				min_index = j;
			}
		}
		swap(a[min_index], a[i]); // Swaps the found minimum element with the first element.
	}
}

// Bubble Sort
void bubbleSort(int* a, int n, ll& comparison_count) {
	comparison_count = 0;
	for (int i = 0; i < n - 1; i++) { // Loops through the array.
		for (int j = 0; j < n - i - 1; j++) { // Moves the largest element to the end.
			comparison_count++;
			if (a[j] > a[j+1]) { // Swaps if the current element is greater than the next element.
				swap(a[j], a[j+1]); 
			}
		}
	}
}

// Shaker Sort 
void shakerSort(int* a, int n, ll& comparison_count) {
	comparison_count = 0;
	bool swapped = true;
	int start = 0;
	int end = n - 1;

	while (swapped) { // Continues if a swap has been made.
		swapped = false;

		for (int i = start; i < end; i++) { // Moves the largest element to the end.
			comparison_count++;
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}

		if (!swapped) { // Breaks if no swap has been made.
			break;
		}

		swapped = false;
		end--;

		for (int i = end - 1; i >= start; i--) { // Moves the smallest element to the start.
			comparison_count++;
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}

		start++;
	}
}

// Shell Sort
void shellSort(int* a, int n, ll& comparison_count) {
	comparison_count = 0;
	for (int gap = n / 2; gap > 0; gap /= 2) { // Starts with a large gap and reduces it.
		for (int i = gap; i < n; i++) {
			int temp = a[i];
			int j;
			for (j = i; j >= gap && a[j - gap] > temp; j -= gap) {  // Sorts the subarray created by the gap.
				comparison_count++;
				a[j] = a[j - gap];
			}
			comparison_count++; // Increments the comparison count for the inner for loop condition check.
			a[j] = temp; // Places the element at its correct position in the subarray.
		}
	}
}

// Heap Sort
void Heapify(int* a, int n, int i, ll& comparison_count) {
	int largest = i;
	int left = 2 * i - 1; // Corrected the index for left child.
	int right = 2 * i + 2; // Corrected the index for right child.

	comparison_count++;
	if (left < n && a[left] > a[largest]) {
		largest = left;
	}

	comparison_count++;
	if (right<n && a[right] > a[largest]) {
		largest = right;
	}

	if (largest != i) { // If the largest is not the root.
		swap(a[i], a[largest]); 
		Heapify(a, n, largest, comparison_count); // Recursively heapifies the affected sub-tree.
	}
}

void heapSort(int* a, int n, ll& comparison_count) {
	comparison_count = 0;
	for (int i = n / 2 - 1; i >= 0; i--) { // Builds a max heap.
		Heapify(a, n, i, comparison_count);
	}

	for (int i = n - 1; i > 0; i--) { // Extracts elements from the heap one by one.
		swap(a[0], a[i]);
		Heapify(a, i, 0, comparison_count); // Calls heapify on the reduced heap.
	}
}

// Merge Sort
void Merge(int* a, int left, int middle, int right, ll& comparison_count) {
	// Sizes of the two subarrays to be merged.
	int n1 = middle - left + 1; 
	int n2 = right - middle;

	int* L = new int[n1]; // Temporary arrays.
	int* R = new int[n2];
	
	// Copies data to temporary arrays L[] and R[].
	for (int i = 0; i < n1; i++) { 
		L[i] = a[left + i];
	}
	for (int j = 0; j < n2; j++) {
		R[j] = a[middle + 1 + j];
	}

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) { // Merges the temporary arrays back into a[].
		comparison_count++;
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) { // Copies the remaining elements of L[], if any.
		a[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) { // Copies the remaining elements of R[], if any.
		a[k] = R[j];
		j++;
		k++;
	}
	
	// Frees the allocated memory.
	delete[] L;
	delete[] R;
}

void mergeSort(int* a, int left, int right, ll& comparison_count) {
	if (left < right) { // Checks if the array has more than one element.
		comparison_count = 0;
		int middle = left + (right - 1) / 2; // Finds the middle point.
		mergeSort(a, left, middle, comparison_count); // Sorts the first half.
		mergeSort(a, middle + 1, right, comparison_count); // Sorts the second half.
		Merge(a, left, middle, right, comparison_count); // Merges the sorted halves.
	}
}
// this function is used to wrap the merge sort function in order to eliminate the left and right variables
void WrappedMergeSort(int* a, int n, ll& comparison_count) {
	mergeSort(a, 0, n - 1, comparison_count);
}

// Quick Sort
int Partition(int* a, int low, int high, ll& comparison_count) {
	int pivot = a[high]; // Chooses the last element as the pivot.
	int i = low - 1;

	for (int j = low; j < high; j++) { // Partitions the array around the pivot.
		comparison_count++;
		if (a[j] < pivot) {
			i++;
			swap(a[i], a[j]);
		}
	}

	swap(a[i + 1], a[high]); // Places the pivot in its correct position.
	return (i + 1);
}

void quickSort(int* a, int low, int high, ll& comparison_count) {
	if (low < high) { // Checks if the array has more than one element.
		comparison_count = 0;
		int p = Partition(a, low, high, comparison_count); // Partitions the array.
		quickSort(a, low, p - 1, comparison_count); // Sorts the elements before the partition.
		quickSort(a, p + 1, high, comparison_count); // Sorts the elements after the partition.
	}
}

// this function is used to wrap the quick sort function in order to eliminate the low and high variables
void WrappedQuickSort(int* a, int n, ll& comparison_count) {
	quickSort(a, 0, n - 1, comparison_count);
}
// Counting Sort
void countingSort(int* a, int n, ll& comparison_count) {
	comparison_count = 0;
	int max = *max_element(a, a + n); // Finds the maximum element in the array.
	int* count = new int [max + 1] {0}; // Creates a count array to store the count of each unique object.

	for (int i = 0; i < n; i++) {
		count[a[i]]++;
	}

	int index = 0;
	for (int i = 0; i <= max; i++) {
		while (count[i]--) {
			a[index++] = i; // Copies the count array to the original array.
		}
	}

	delete[] count; // Frees the allocated memory.
}

// Radix Sort 
int getMax(int* a, int n, ll& comparison_count) {
	int max = a[0];
	for (int i = 1; i < n; i++) {
		comparison_count++;
		if (a[i] > max)
		max = a[i]; // Updates the maximum element.
	}
	return max;
}

void countSort(int* a, int n, int exp) {
	int* output = new int[n]; // Output array.
	int count[10] = { 0 }; // Count array for each digit.

	for (int i = 0; i < n; i++) { // Stores count of occurrences in count[].
		count[(a[i] / exp) % 10]++;
	}

	for (int i = 1; i < 10; i++) {
		count[i] += count[i - 1]; // Changes count[i] so that count[i] contains the actual position of this digit in output[].
	}

	// Builds the output array.
	for (int i = n - 1; i >= 0; i--) { 
		output[count[(a[i] / exp) % 10] - 1] = a[i];
		count[(a[i] / exp) % 10]--;
	}

	// Copies the output array to a[], so that a[] now contains sorted numbers according to the current digit.
	for (int i = 0; i < n; i++) {
		a[i] = output[i];
	}

	delete[] output; // Frees the allocated memory.
}

void radixSort(int* a, int n, ll& comparison_count) {
	comparison_count = 0;
	int m = getMax(a, n, comparison_count); // Finds the maximum number to know the number of digits.

	for (int exp = 1; m / exp > 0; exp *= 10) {
		countSort(a, n, exp); // Performs counting sort for every digit.
	}
}

// Flash Sort
void flashSort(int* a, int n, ll& comparison_count) {
	comparison_count = 0;
	if (n == 0) {
		return; // If the array is empty, returns immediately.
	}

	int m = int(0.45 * n); // Number of classes.
	if (m <= 1) {
		m = 2;
	}

	int Min = a[0], Max = a[0];
	int* l = new int[m]();

	// Finds the minimum and maximum elements.
	for (int i = 1; i < n; i++) {
		comparison_count = 0;
		if (a[i] < Min) {
			Min = a[i];
		}

		if (a[i] > Max) {
			Max = a[i];
		}
	}

	if (Min == Max) { // If all elements are the same, returns immediately.
		return;
	}

	double c1 = (double)(m - 1) / (Max - Min); // Scaling factor.

	for (int i = 0; i < n; i++) {
		int k = int(c1 * (a[i] - Min)); // Classifies the elements into classes.
		l[k]++;
	}

	for (int i = 1; i < m; i++) {
		l[i] += l[i - 1]; // Transforms l[] to be the starting index of each class.
	}

	swap(a[0], a[Max]); // Places the maximum element at the first position.

	int nMove = 0;
	int j = 0;
	int k = m - 1;
	int flash;

	while (nMove < n - 1) {
		while (j > l[k] - 1) { // Finds the first element not in its class.
			j++;
			k = int(c1 * (a[j] - Min));
		}
		flash = a[j];
		while (j != l[k]) {
			k = int(c1 * (flash - Min));
			swap(a[--l[k]], flash); // Swaps the elements to their correct positions.
			nMove++;
		}
	}

	delete[] l; // Frees the allocated memory.
	binaryInsertionSort(a, n, comparison_count);// Performs insertion sort to finalize the sort.
}