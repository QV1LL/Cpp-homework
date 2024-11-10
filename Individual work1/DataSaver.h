#pragma once

#include "GameLibrary.h"

#include <iostream>

struct DataSaver {
private:
	static DataSaver* instance;

	DataSaver() = default;

public:

	auto saveData(GameLibrary* gameLibrary,
		const std::string& saveFileName) -> void;

	static auto getInstance() -> DataSaver*;
};