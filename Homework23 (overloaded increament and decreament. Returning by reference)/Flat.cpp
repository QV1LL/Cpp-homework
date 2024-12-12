#include <iostream>

#include "Flat.h"

Flat::Flat(double square, int price){
	if (square <= 0 || price < 0)
		throw std::invalid_argument("Square or price cannot be negative!");

	this->square = square;
	this->price = price;
}

Flat& Flat::operator=(const Flat& other) {
	if (&other == this)
		return *this;

	this->price = other.price;
	this->square = other.square;

	return *this;
}
