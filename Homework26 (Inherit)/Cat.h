#pragma once

#include "Animal.h"

class Cat : public Animal
{
private:

	double speed;

public:

	Cat(const String& name, double speed)
		: Animal(name)
	{
		if (speed <= 0) 
			throw std::invalid_argument("Speed cannot be negative value!");

		this->speed = speed;
	}
};

