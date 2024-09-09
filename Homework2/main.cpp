#include <iostream>

using namespace std;

void task1() {
	char symbol;
	cout << "Enter symbol: ";
	cin >> symbol;

	int symbolIndex = (int)symbol;

	if ((32 <= symbolIndex && symbolIndex <= 47)
		|| (58 <= symbolIndex && symbolIndex <= 64)
		|| (123 <= symbolIndex && symbolIndex <= 126)) {
		cout << "Its a symbol!";
	}
	else if (48 <= symbolIndex && symbolIndex <= 57) {
		cout << "Its a number!";
	}
	else {
		cout << "Its a letter!";
	}
}

void task2() {
	float price;
	string mobileOperator;

	cout << "Enter operator: ";
	cin >> mobileOperator;

	cout << "Enter price: ";
	cin >> price;

	float bilineKoef = 1.0f;
	float vodafoneKoef = 2.0f;
	float kyevstarKoef = 3.0f;

	if (mobileOperator == "biline")
		cout << "Price of call: " << price * bilineKoef;
	else if (mobileOperator == "vodafone")
		cout << "Price of call: " << price * vodafoneKoef;
	else if (mobileOperator == "kyevstar")
		cout << "Price of call: " << price * kyevstarKoef;
	else
		cout << "This operator does not exist";
}

void task3() {
	const int SALARY_PER_WORK = 50;
	const int GET_LATE_PRICE = 20;

	short choice;
	cout << "Enter desired salary and count of get late(1)\n"
		<< "Enter count of line and desired amount of salary(2)\n"
		<< "Enter count of line and count of get late(3): ";
	cin >> choice;

	if (choice == 1) {
		float desiredSalary;
		int countOfGetLate;

		cout << "Enter desired salary: ";
		cin >> desiredSalary;

		cout << "Enter count of get late: ";
		cin >> countOfGetLate;

		cout << "You need to write " << (desiredSalary + countOfGetLate * GET_LATE_PRICE) / SALARY_PER_WORK * 100 << " lines.";
	}
	else if (choice == 2) {
		float desiredSalary;
		int countOfLines;

		cout << "Enter desired salary: ";
		cin >> desiredSalary;

		cout << "Enter count lines: ";
		cin >> countOfLines;

		cout << "You can get late for a " << (((countOfLines * SALARY_PER_WORK / 100) - desiredSalary) / GET_LATE_PRICE < 0) ? 0 : ((countOfLines * SALARY_PER_WORK / 100) - desiredSalary) / GET_LATE_PRICE;
	}
}

int main() {
	task3();

	return 0;
}