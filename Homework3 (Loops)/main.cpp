#include <iostream>

using namespace std;

// Sum of number in range a : 500
void task1() {
	int rangeSum = 0;
	int startOfRange;

	cout << "Enter start: ";
	cin >> startOfRange;

	for (int i = startOfRange; i <= 500; i++) rangeSum += i;
	cout << "Sum of numbers from " << startOfRange << " to 500: " << rangeSum;
}

// Get the pow of number
void task2() {
	int number;
	int pow;

	cout << "Enter number: ";
	cin >> number;

	cout << "Enter power: ";
	cin >> pow;

	int result = number;

	if (pow) {
		for (int i = 1; i < pow; i++) result *= number;
	}
	else {
		result = 0;
	}
	cout << "Result: " << result;
}

// Get the average arithmetic of range 1 : 1000
void task3() {
	int rangeSum = 0;
	int elementsCount = 1000;

	for (int i = 1; i <= elementsCount; i++) rangeSum += i;

	cout << "Average arithmetic: " << rangeSum / elementsCount;
}

// Get the mul in range a : 20
void task4() {
	int startOfRange;
	int topOfRange = 20;
	long long rangeMul = 1;

	cout << "Enter start of range (1 <= input <= 20): ";
	cin >> startOfRange;

	for (int i = startOfRange; i <= topOfRange; i++) rangeMul *= i;
	cout << "Mul of range: " << rangeMul;
}

void task5() {
	int number;
	cout << "Enter a number: ";
	cin >> number;

	for (int i = 2; i <= 10; i++) {
		cout << number << " x " << i << " = " << number * i << endl;
	}
}

int main() {

	return 0;
}