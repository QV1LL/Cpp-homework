#include <iostream>

#include "Airplane.h"

Airplane::Airplane(AirplaneType airplaneType, int passangersCount) : airplaneType(airplaneType) {
	if (passangersCount <= 0)
		throw std::invalid_argument("Cannot decrease the empty count of passangers!");

	this->passangersCount = passangersCount;
}

void Airplane::operator++(int) {
	this->passangersCount++;
}

void Airplane::operator--(int) {
	if (this->passangersCount <= 0)
		throw std::invalid_argument("Cannot decrease the empty count of passangers!");

	this->passangersCount++;
}