#include <iostream>
#include <chrono>

#include "ProductionYear.h"

ProductionYear::ProductionYear(size_t year)
{
	if (this->getCurrentYear() < year)
		std::invalid_argument("Production year cannot be greater than current");

	if (year < 1908)
		std::invalid_argument("First serial car was producted in 1908...");

	this->year = year;

}
