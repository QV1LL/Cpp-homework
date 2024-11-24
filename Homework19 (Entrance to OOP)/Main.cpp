#include <iostream>

#include "Fraction.h"

auto getBiggestDivider(int number1, int number2) -> int {
	while (number2 != 0) {
		int remainder = number1 % number2;
		number1 = number2;
		number2 = remainder;
	}
	return number1;
}

auto getTheLeastCommonMultiple(int number1, int number2) -> int {
	int biggestDivider = getBiggestDivider(number1, number2);
	return std::abs(number1 * number2) / biggestDivider; 
}

int main() {
	Fraction frac1(7455, 2464);
	Fraction frac2(164, 11465);

	std::cout << (frac1 + frac2).toString() << '\n';
	std::cout << (frac1 - frac2).toString() << '\n';
	std::cout << (frac1 * frac2).toString() << '\n';
	std::cout << (frac1 / frac2).toString() << "\n \n";

	return 0;
}