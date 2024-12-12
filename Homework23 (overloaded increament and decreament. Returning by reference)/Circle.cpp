#include <iostream>

#include "Circle.h"

Circle::Circle(double radius) {
	if (radius <= 0)
		throw std::invalid_argument("Radius cannot be negative!");
	
	this->radius = radius;
}