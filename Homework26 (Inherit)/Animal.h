#pragma once

#include <iostream>

#include "String.h"

class Animal
{
private:

	String name;

public:

	explicit Animal(const String& name) : name(name)
	{

	}
};

