#include <iostream>
#include <time.h>

using namespace std;

template <class T>
auto quickSort(T array[], int first, int last) -> void;

template <class T>
auto sortArray(T array[], size_t size, bool decreasingSort = false) -> void;

template <class T>
auto insertionSort(T array[], int start, int end) -> void;

template <class T>
auto sortHalfsOfArrayByDecreasingAndIncreasing(T array[], size_t size) -> void;

template <class T>
auto sortBetweenFirstAndLastNegative(T array[], size_t size) -> void;


int main() {
	srand(time(NULL));

	const int SIZE = 200;
	int array[SIZE];

	for (int i = 0; i < SIZE; i++)
		array[i] = (rand() % 100000) * ((rand() % 2 == 0) ? -1 : 1);

	for (int element : array)
		cout << element << " ";

	cout << "\n\n";

	sortBetweenFirstAndLastNegative(array, SIZE);

	for (int element : array)
		cout << element << " ";

	return 0;
}

//********************************************* TASK1 *********************************************

// We`ll sorting our array by quick sort algorithm
template <class T>
auto quickSort(T array[], int first, int last) -> void {
	int middle = (first + last) / 2;

	int i = first;
	int j = last;

	do {
		while (array[i] < array[middle]) i++;
		while (array[j] > array[middle]) j--;

		if (i <= j) {
			swap(array[i], array[j]);
			i++;
			j--;
		}

	} while (i <= j);

	if (i < last) quickSort(array, i, last);
	if (j > first) quickSort(array, first, j);
}

// We`ll just reverse array if decreasingSort = true
template <class T>
auto sortArray(T array[], size_t size, bool decreasingSort) -> void {
	quickSort(array, 0, size - 1);

	if (decreasingSort) {
		for (int i = 0; i < size / 2; i++) {
			swap(array[i], array[size - 1 - i]);
		}
	}
}

//********************************************* TASK2 *********************************************

// We need to use insertion sort by task
template <class T>
auto insertionSort(T array[], int start, int end) -> void {
	for (int i = start; i <= end; i++) {

		int j = i;

		for (j = i - 1; j > start && array[j - 1] > array[j]; j--) {
			swap(array[j - 1], array[j]);
		}
	}
}

// Giving our halfs to insertion sort and reverse first half
template <class T>
auto sortHalfsOfArrayByDecreasingAndIncreasing(T array[], size_t size) -> void {
	int middle = size / 2;

	insertionSort(array, 0, size / 2);
	insertionSort(array, size / 2, size);

	for (int i = 0; i < middle / 2; i++) {
		swap(array[i], array[middle - 1 - i]);
	}
}

//********************************************* TASK3 *********************************************

// Finding first negative and last negative and sorting array in this area
template <class T>
auto sortBetweenFirstAndLastNegative(T array[], size_t size) -> void {
	int firstNegativeIndex = 0;
	int lastNegativeIndex = 0;

	for (int i = 0; i < size; i++) {
		if (array[i] < 0) {
			firstNegativeIndex = i;
			break;
		}
	}

	for (int i = size - 1; i > 0; i--) {
		if (array[i] < 0) {
			lastNegativeIndex = i;
			break;
		}
	}

	insertionSort(array, firstNegativeIndex + 1, lastNegativeIndex);
}