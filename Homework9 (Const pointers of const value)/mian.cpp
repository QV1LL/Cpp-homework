#include <iostream>
#include <time.h>

using namespace std;

//***************************** Task1 *****************************
template<class T>
auto getUniqueElementsFromFirstArray(T array1[], const int& array1Size, T array2[], const int& array2Size, int& uniqueElementsArraySize) -> T* {
	int futureArraySize = 0;
	T* uniqueElementsIndex = new T[array1Size];
	
	for (int i = 0; i < array1Size; i++) {
		bool isUniqueForBothArrays;

		for (int j = 0; j < array2Size; j++) {
			isUniqueForBothArrays = !(array1[i] == array2[j]);

			if (!isUniqueForBothArrays) break;
		}

		if (isUniqueForBothArrays) {
			futureArraySize++;
			uniqueElementsIndex[i] = i;
		}

		else uniqueElementsIndex[i] = -1;
	}

	uniqueElementsArraySize = futureArraySize;
	T* result = new T[futureArraySize];

	int i = 0;
	int j = 0;

	while (i < futureArraySize) {
		if (uniqueElementsIndex[j] != -1) {
			result[i] = array1[uniqueElementsIndex[j]];
			
			i++; j++;
		}
		else {
			j++;
		}
	}

	delete[] uniqueElementsIndex;

	return result;
}

//***************************** Task2 *****************************
template<class T>
auto writeUniqueElementsIndexInArray(T* uniqueElementsIndex, T array[], const int& arraySize, T compareArray[], const int& compareArraySize, int& futureArraySize) -> void {
	for (int i = 0; i < arraySize; i++) {
		bool isUniqueForBothArrays;

		for (int j = 0; j < compareArraySize; j++) {
			isUniqueForBothArrays = !(array[i] == compareArray[j]);

			if (!isUniqueForBothArrays) break;
		}

		if (isUniqueForBothArrays) {
			futureArraySize++;
			uniqueElementsIndex[i] = i;
		}

		else uniqueElementsIndex[i] = -1;
	}
}

template<class T>
auto getUniqueElementsFromArrays(T array1[], const int& array1Size, T array2[], const int& array2Size, int& uniqueElementsArraySize) -> T* {
	int futureArraySize = 0;

	T* uniqueElementsFromFirstArrayIndex = new T[array1Size];
	T* uniqueElementsFromSecondArrayIndex = new T[array2Size];

	writeUniqueElementsIndexInArray(uniqueElementsFromFirstArrayIndex, array1, array1Size, array2, array2Size, futureArraySize);
	writeUniqueElementsIndexInArray(uniqueElementsFromSecondArrayIndex, array2, array2Size, array1, array1Size, futureArraySize);

	uniqueElementsArraySize = futureArraySize;
	T* result = new T[futureArraySize];

	int i = 0;
	int firstIterator = 0;
	int secondIterator = 0;

	while (i < futureArraySize) {
		if (firstIterator < array1Size) {
			if (uniqueElementsFromFirstArrayIndex[firstIterator] != -1) {
				result[i] = array1[uniqueElementsFromFirstArrayIndex[firstIterator]];

				i++; firstIterator++;
			}
			else {
				firstIterator++;
			}
		}

		else {
			if (uniqueElementsFromSecondArrayIndex[secondIterator] != -1) {
				result[i] = array2[uniqueElementsFromSecondArrayIndex[secondIterator]];

				i++; secondIterator++;
			}
			else {
				secondIterator++;
			}
		}
	}

	delete[] uniqueElementsFromFirstArrayIndex;
	delete[] uniqueElementsFromSecondArrayIndex;

	return result;
}

int main() {
	srand(time(0));

	const int size1 = 100;
	const int size2 = 100;

	int array1[size1];
	int array2[size2];

	for (int i = 0; i < size1; i++)
		array1[i] = i + 1;

	for (int i = 0; i < size2; i++)
		array2[i] = i + 4;
	
	int size3;
	int* array3 = getUniqueElementsFromArrays(array1, size1, array2, size2, size3);

	for (int el : array1)
		cout << el << " ";

	cout << endl;

	for (int el : array2)
		cout << el << " ";

	cout << endl;

	for (int i = 0; i < size3; i++)
		cout << array3[i] << " ";

	return 0;
}