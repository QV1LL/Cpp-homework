#include <iostream>

#include "PhoneNumber.h"
#define countOfSymbolsInNumber 14

PhoneNumber::PhoneNumber(const std::string& number) {
	this->setNumber(number);
}

auto PhoneNumber::setNumber(const std::string& number) -> void {
	if (number[0] != '+' && number.size() != countOfSymbolsInNumber)
		throw std::invalid_argument("Phone number is incorrect!");

	this->number = number;
}
