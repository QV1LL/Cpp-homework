#pragma once

#include "Animal.h"

class Dog : public Animal
{
private:

	double aggresivity;

public:

	Dog(const String& name, double aggresivity)
		: Animal(name)
	{
		if (aggresivity < 0)
			throw std::invalid_argument("Aggresivity cannot be negative value!");

		this->aggresivity = aggresivity;
	}
};

