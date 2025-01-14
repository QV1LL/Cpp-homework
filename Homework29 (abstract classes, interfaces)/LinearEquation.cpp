#include <iostream>
#include <vector>
#include <string>

#include "Equation.h"

#include "LinearEquation.h"

LinearEquation::LinearEquation(float juniorKoeficient, float freeKoeficient)
	: Equation(freeKoeficient)
{
	if (juniorKoeficient == 0)
		throw std::invalid_argument("Statement " + std::to_string(freeKoeficient) + " is not an equation");

	this->juniorKoeficient = juniorKoeficient;
}

std::vector<float> LinearEquation::getRoots() const
{
	std::vector<float> result;
	result.push_back(-this->freeKoeficient / this->juniorKoeficient);

	return result;
}

LinearEquation::operator std::string() const
{
	return ((this->juniorKoeficient == 1) ? "" : std::to_string(this->juniorKoeficient)) + "x" +
		((this->freeKoeficient <= 0) ? "" : "+") + 
		Equation::operator std::string();
}

