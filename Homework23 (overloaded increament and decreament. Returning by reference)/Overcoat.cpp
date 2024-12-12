#include <iostream>

#include "Overcoat.h"

Overcoat::Overcoat(OvercoatType overcoatType, int price) {
	if (price < 0)
		throw std::invalid_argument("Price cannot be negative!");

	this->price = price;
	this->overcoatType = overcoatType;
}

Overcoat& Overcoat::operator=(const Overcoat& other) {
	if (this == &other)
		return *this;
	
	this->price = other.price;
	this->overcoatType = other.overcoatType;

	return *this;
}
