#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include "Date.h"
#include "String.h"

auto operator-(Date& date1, Date& date2) -> int;

//************************************** Task1 (Date) **************************************
void task1() {
	Date date1{ 1, 9, 1939 };
	Date date2{ 2, 9, 1945 };

	date2.normalize();
	std::cout << (date2 + 10000).toString() << '\n';
	std::cout << date1 - date2 << '\n';
}

//************************************** Task2 **************************************
void task2() {
	(String("sdqcg") * String("rgfas34")).print();
}

int main() {
	task1();
	task2();

	return 0;
}