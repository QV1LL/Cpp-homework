#pragma once

#include "GameLibrary.h"

#include <iostream>

struct DataLoader {
private:
	static DataLoader* instance;

	DataLoader() = default;

public:

	auto loadData(GameLibrary& gameLibrary,
		const std::string& saveFileName) -> void;

	static auto getInstance() -> DataLoader*;
};