#include <iostream>
#include <time.h>

using namespace std;

//***************************** Task1 *****************************
template<class T>
auto getUniquePartOfFirstArray(T& array1, const int array1Size, T& array2, const int array2Size) -> T& {
	int futureArraySize = 0;
	T** pUniqueElements = new T*[array1Size];
	
	for (int i = 0; i < array1Size; i++) {
		bool isUniqueForBothArrays;

		for (int j = 0; j < array2Size; j++) {
			isUniqueForBothArrays = !(array1[i] == array2[j]);

			if (!isUniqueForBothArrays) break;
		}

		if (isUniqueForBothArrays) {
			futureArraySize++;
			pUniqueElements[i] = &array1[i];
		}
		else {
			pUniqueElements[i] = nullptr;
		}
	}

	T* result = new T[futureArraySize];

	int i = 0;
	int j = i;

	while (i < futureArraySize) {
		if (pUniqueElements[j] != nullptr) {
			*result[i] = *pUniqueElements[j];
			
			i++;
			j++;
		}
		else {
			j++;
		}
	}

	return *result;
}

int main() {
	srand(time(0));

	const int size1 = 5;
	const int size2 = 5;

	int array1[size1];
	int array2[size2];

	for (int element : array1)
		element = rand() % 100;

	for (int element : array2)
		element = rand() % 100;

	int* array3 = getUniquePartOfFirstArray(array1, size1, array2, size2);

	for (int el : array1)
		cout << el << " ";

	cout << endl;

	for (int el : array2)
		cout << el << " ";

	cout << endl;

	for (int i = 0; i < sizeof(array3) / sizeof(int); i++)
		cout << array3[i] << " ";

	return 0;
}