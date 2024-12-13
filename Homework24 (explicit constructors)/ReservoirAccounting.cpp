#include "ReservoirAccounting.h"

void ReservoirAccounting::append(const Reservoir& reservoir)
{
	this->reservoirs.push_back(reservoir);
}

void ReservoirAccounting::deleteByIndex(int index)
{
	if (index < 0 || index > this->reservoirs.size())
		throw std::out_of_range("Index was out of range");

	this->reservoirs.erase(this->reservoirs.begin() + index);
}

Reservoir& ReservoirAccounting::operator[](int index)
{
	return this->reservoirs[index];
}
