#pragma once

#include <iostream>

class Fruit
{
private:

	std::string name;
	std::string color;

public:

	Fruit(const std::string& name, const std::string& color)
		: name(name), color(color)
	{
		
	}

	friend std::ostream& operator<< (std::ostream& out, const Fruit& fruit);
};

