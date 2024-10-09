#include <iostream>
#include <functional>
#include <time.h>

using namespace std;

//*********************************************** Task1 ***********************************************
template <class T>
auto getMax(T array[], const int& size) -> T {
	int max = array[0];

	for (int i = 0; i < size; i++)
		max = (array[i] > max) ? array[i] : max;

	return max;
}

template <class T>
auto getMin(T array[], const int& size) -> T {
	int min = array[0];

	for (int i = 0; i < size; i++)
		min = (array[i] < min) ? array[i] : min;

	return min;
}

template <class T>
auto getAverage(T array[], const int& size) -> T {
	int average = 0;

	for (int i = 0; i < size; i++)
		average += array[i];

	return average / size;
}

template<class T>
auto action(T array1[], const int& array1Size, T array2[], const int& array2Size, function<T(T[], const int&)> func) -> T {
	T value1 = func(array1, array1Size);
	T value2 = func(array2, array2Size);

	T values[]{ value1, value2 };
	return func(values, 2);
}

template <class T>
auto getUserChoice(T array[]) -> function<T(T[], const int&)> {
	string choice;
	
	while (true) {
		cout << "Enter an action (max, min, average): ";
		cin >> choice;

		if (choice == "max")
			return getMax<T>;
		else if (choice == "min")
			return getMin<T>;
		else if (choice == "average")
			return getAverage<T>;

		cout << "Invalid function name, please write correct value." << endl;
	}
}

int main() {
	srand(time(0));

	const int size1 = 10;
	char array1[size1];

	const int size2 = 10;
	char array2[size2];

	for (int i = 0; i < size1; i++) {
		array1[i] = rand() % 100 * ((rand() % 2 == 0) ? 1 : -1);
		array2[i] = rand() % 100 * ((rand() % 2 == 0) ? 1 : -1);
	}

	for (int i = 0; i < size1; i++) {
		cout << array1[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < size1; i++) {
		cout << array2[i] << " ";
	}

	cout << endl;

	auto func = getUserChoice(array1);
	char result = action(array1, size1, array2, size2, func);

	cout << "Result: " << result;

	return 0;
}