#include <cstdlib> 
#include <iostream>
#include <time.h> 
#include <typeinfo>

using namespace std;

void task1() {
	const int massiveSize = 100;

	int massive[massiveSize];

	bool minMaxDefined = false;
	int minElement;
	int maxElement;

	for (int i = 0; i < massiveSize; i++) {
		massive[i] = rand() % 1000;

		if (minMaxDefined) {
			if (minElement > massive[i])
				minElement = massive[i];
			else if (maxElement < massive[i])
				maxElement = massive[i];
		}
		else {
			minElement = massive[i];
			maxElement = massive[i];

			minMaxDefined = !minMaxDefined;
		}
	}

	cout << "Min in massive: " << minElement << ", max: " << maxElement;
}

void task2() {
	const int monthCount = 12;

	int monthsSalary[monthCount];

	bool minMaxDefined = false;
	int minSalary;
	int maxSalary;

	int minSalaryIndex;
	int maxSalaryIndex;

	int i = 0;

	while (i < monthCount) {
		int salary;

		cout << "Enter salary for " << i + 1 << " month: ";
		cin >> salary;

		if (salary < 0) {
			cout << "Salary cannot be negative!" << endl;
			continue;
		}

		monthsSalary[i] = salary;
		i++;
	}

	int start;
	int end;

	while (true) {
		cout << "Enter start: ";
		cin >> start;

		cout << "Enter end: ";
		cin >> end;

		start--; 
		end--;

		if ((0 <= start && start < monthCount) && (0 <= end && end < monthCount)) {
			if (start > end) {
				start, end = end, start;
			}

			break;
		}
		else {
			cout << ((start < 0) ? "Start" : "End") << " value must be grather than zero!" << endl;
		}
	}

	for (int i = start; i <= end; i++) {
		if (minMaxDefined) {
			if (minSalary > monthsSalary[i]) {
				minSalary = monthsSalary[i];
				minSalaryIndex = i + 1;
			}
			else if (maxSalary < monthsSalary[i]) {
				maxSalary = monthsSalary[i];
				maxSalaryIndex = i + 1;
			}
		}
		else {
			minSalary = monthsSalary[i];
			maxSalary = monthsSalary[i];

			minSalaryIndex = i + 1;
			maxSalaryIndex = i + 1;

			minMaxDefined = true;
		}
	}

	cout << "Min salary was in month " << minSalaryIndex << ", max in " << maxSalaryIndex;
}

void task3() {
	const int numbersSize = 10;

	int numbers[numbersSize];

	int negativesSum = 0;
	int multipleOfPairIndex = 1;
	int betweenFirstAndLastNegativeSum = 0;
	int beetweenMinMaxMultiple = 1;

	bool minMaxDefined = false;

	int minNumber;
	int maxNumber;

	int minNumberIndex;
	int maxNumberIndex;

	int firstNegativeIndex = 0;
	int lastNegativeIndex = 0;

	for (int i = 0; i < numbersSize; i++) {
		numbers[i] = rand() % 100 * ((rand() % 2 == 0) ? 1 : -1);
		int currentNumber = numbers[i];

		if (currentNumber < 0) {
			negativesSum += currentNumber;
			lastNegativeIndex = i;

			firstNegativeIndex = (!firstNegativeIndex) ? i : firstNegativeIndex;
		}

		if (i % 2 == 0)
			multipleOfPairIndex *= currentNumber;

		if (minMaxDefined) {
			if (minNumber > currentNumber) {
				minNumber = currentNumber;
				minNumberIndex = i;
			}
			else if (maxNumber < currentNumber) {
				maxNumber = currentNumber;
				maxNumberIndex = i;
			}
		}
		else {
			minNumber = currentNumber;
			maxNumber = currentNumber;

			minNumberIndex = i;
			maxNumberIndex = i;

			minMaxDefined = true;
		}
	}

	for (int number : numbers) {
		cout << number << " ";
	}

	if (minNumberIndex > maxNumberIndex)
		minNumberIndex, maxNumberIndex = maxNumberIndex, minNumberIndex;

	for (int i = 0; i < numbersSize; i++) {
		int currentNumber = numbers[i];

		if (minNumberIndex < i && maxNumberIndex > i)
			beetweenMinMaxMultiple *= currentNumber;

		if (firstNegativeIndex < i & lastNegativeIndex > i)
			betweenFirstAndLastNegativeSum += currentNumber;
	}

	cout << "\nSum of negatives: " << negativesSum << endl
		<< "Mul between min and max: " << beetweenMinMaxMultiple << endl
		<< "Mul of pair index: " << multipleOfPairIndex << endl
		<< "Sum between first and last negatives: " << betweenFirstAndLastNegativeSum << endl;
 }

int main() {
	srand(time(NULL));

	return 0;
}