#pragma once

#include <iostream>

#include "ReservoirAccounting.h"
#include "Reservoir.h"

class DataSaver {
private:
	static DataSaver* instance;

	DataSaver() = default;

public:

	auto saveData(ReservoirAccounting* reservoirAccounting,
		const std::string& saveFileName) -> void;

	static auto getInstance() -> DataSaver*;
};