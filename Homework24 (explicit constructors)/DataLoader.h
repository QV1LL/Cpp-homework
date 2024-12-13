#pragma once

#include <iostream>

#include "ReservoirAccounting.h"
#include "Reservoir.h"

struct DataLoader {
private:
	static DataLoader* instance;

	DataLoader() = default;

public:

	auto loadData(ReservoirAccounting& reservoirAccounting,
		const std::string& saveFileName) -> void;

	static auto getInstance() -> DataLoader*;
};