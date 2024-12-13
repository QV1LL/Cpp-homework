#pragma once

#include <iostream>
#include <vector>

#include "Reservoir.h"

class ReservoirAccounting
{
private:

	std::vector<Reservoir> reservoirs;

public:

	std::vector<Reservoir> getReservoirs() const { return this->reservoirs; }

	void append(const Reservoir& reservoir);
	void deleteByIndex(int index);

	Reservoir& operator[] (int index);
};

