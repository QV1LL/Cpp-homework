#include "complexNumber.h"
#include "car.h"
#include <iostream>

using namespace std;

//************************************** Task1 **************************************
// Task 1 solution is in complexNumberArythmetics.cpp and complexNumber.h

auto printComplexNumber(ComplexNumber complexNumber) -> void;

auto getSumOfComplexNumbers(ComplexNumber complexNumber1, ComplexNumber complexNumber2) -> ComplexNumber;

auto getSubstractOfComplexNumbers(ComplexNumber complexNumber1, ComplexNumber complexNumber2) -> ComplexNumber;

auto getMultiplyOfComplexNumbers(ComplexNumber complexNumber1, ComplexNumber complexNumber2) -> ComplexNumber;

auto getDivisionOfComplexNumbers(ComplexNumber complexNumber1, ComplexNumber complexNumber2) -> ComplexNumber;

//************************************** Task2 **************************************
// Task 2 is located in car.h, so as we didnt learn methods and modifiers (and i can`t use it) i can`t normaly realise set and get of struct values :(, but we can get and set them by -> expression )))

void printCarStatements(Car car) {
	std::cout << "Length: " << car.length << std::endl;
	std::cout << "Suspension heigth: " << car.suspensionHeigth << std::endl;
	std::cout << "Wheel size: " << car.wheelSize << std::endl;
	std::cout << "Engine volume: " << car.engineVolume << std::endl;
	std::cout << "Engine power (in horse powers): " << car.enginePower << std::endl;
	std::cout << "Gearbox type: " << GEAR_BOX_TYPE_NAMES[(int)car.gearBoxType] << std::endl;
	printf("Body color: red %g, green %g, blue %g, transparent %g", car.bodyColor.r, car.bodyColor.g, car.bodyColor.b, car.bodyColor.transparent);

}

int main() {
	Car lotus_exige{
		2.5,
		0.12,
		16,
		2.2,
		343,
		GearBoxType::DUAL_CLUTCH,
		Color {100, 100, 100},
	};

	printCarStatements(lotus_exige);

	return 0;
}