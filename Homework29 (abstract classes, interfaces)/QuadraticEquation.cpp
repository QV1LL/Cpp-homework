#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>

#include "Equation.h"
#include "LinearEquation.h"

#include "QuadraticEquation.h"

QuadraticEquation::QuadraticEquation(float seniorKoeficient, 
	float juniorKoeficient, 
	float freeKoeficient)
	: LinearEquation(juniorKoeficient, freeKoeficient)
{
	if (seniorKoeficient == 0)
		throw std::invalid_argument("In quadratic equation senior koeficient must be non-zero real number");

	this->seniorKoeficient = seniorKoeficient;
}

std::vector<float> QuadraticEquation::getRoots() const
{
	std::vector<float> result;

	float discriminant = this->juniorKoeficient * this->juniorKoeficient - 4 * this->seniorKoeficient * this->freeKoeficient;

	if (discriminant < 0)
		throw std::domain_error("Cannot execute square root from negative number");

	result.push_back(
		(-this->juniorKoeficient + std::sqrt(discriminant)) / 2 * this->seniorKoeficient
	);

	result.push_back(
		(-this->juniorKoeficient - std::sqrt(discriminant)) / 2 * this->seniorKoeficient
	);

	return result;
}

QuadraticEquation::operator std::string() const
{
	return ((this->seniorKoeficient == 1) ? "" : std::to_string(this->seniorKoeficient)) + "x^2" +
		((this->juniorKoeficient < 0) ? "" : "+") + 
		LinearEquation::operator std::string();
}