#include <iostream>
#include <vector>
#include <string>

#include "Equation.h"

Equation::Equation(float freeKoeficient)
{
	if (freeKoeficient == 0)
		throw std::invalid_argument("Free koeficient must be non-zero real number");

	this->freeKoeficient = freeKoeficient;
}

Equation::operator std::string() const
{
	return (this->freeKoeficient == 0) ? "" : std::to_string(this->freeKoeficient);
}
