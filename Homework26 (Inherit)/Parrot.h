#pragma once

#include "Animal.h"

class Parrot : public Animal
{
private:

	double maxFlyTime;

public:

	Parrot(const String& name, double maxFlyTime)
		: Animal(name)
	{
		if (maxFlyTime < 0)
			throw std::invalid_argument("Time cannot be negative value!");

		this->maxFlyTime = maxFlyTime;
	}
};

