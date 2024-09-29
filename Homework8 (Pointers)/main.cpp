#include <iostream>
#include <time.h>

using namespace std;

//************************ Task1 ************************

// Copy array to other using pointers
template <class T>
void copyArrayTo(T* array, T* copyToArray, size_t arraysSize) {
	for (int i = 0; i < arraysSize; i++) {
		*(copyToArray + i) = *(array + i);
	}
}

//************************ Task2 ************************

// Reverse array using pointers
template <class T>
void reverseArray(T* array, size_t arraySize) {
	for (int i = 0; i < arraySize / 2; i++) {
		T el1 = *(array + i);
		T el2 = *(array + (arraySize - 1 - i));

		__asm {
			mov eax, el1
			mov ebx, el2

			mov el1, ebx
			mov el2, eax
		}

		*(array + i) = el1;
		*(array + (arraySize - 1 - i)) = el2;

	}
}

//************************ Task3 ************************
 
template <class T>
void copyToArrayWithReverse(T* array, T* copyToArray, size_t arraysSize) {
	copyArrayTo(array, copyToArray, arraysSize);
	reverseArray(copyToArray, arraysSize);
}


int main() {
	srand(time(0));

	const int SIZE = 10;

	int array[SIZE];
	int array2[SIZE];

	for (int i = 0; i < SIZE; i++)
		array[i] = rand() % 100;

	for (int element : array)
		cout << element << " ";

	cout << endl;

	copyToArrayWithReverse(array, array2, SIZE);

	for (int element : array2)
		cout << element << " ";

	cout << endl;

	return 0;
}