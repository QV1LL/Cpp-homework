#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>

#include "Price.h"

Price::Price(float price)
{
	if (price < 0)
		std::invalid_argument("Price cannot be negative");

	this->fullPart = price;
	this->hundredthPart = int(price * 100) % 100;
}

Price::Price(int fullPart, int hundredthPart)
{
	if (fullPart < 0)
		std::invalid_argument("Full part of price cannot be negative");

	if (hundredthPart < 0)
		std::invalid_argument("Hundredth part of price cannot be negative");

	this->fullPart = fullPart;
	this->hundredthPart = hundredthPart;
}
