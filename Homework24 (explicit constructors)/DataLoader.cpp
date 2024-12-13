#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "DataLoader.h"
#include "ReservoirAccounting.h"
#include "Reservoir.h"

DataLoader* DataLoader::instance = nullptr;

auto DataLoader::getInstance() -> DataLoader* {
	if (DataLoader::instance == nullptr)
		instance = new DataLoader();

	return instance;
}


auto DataLoader::loadData(ReservoirAccounting& reservoirAccounting,
	const std::string& saveFileName) -> void {

	std::ifstream saveFile(saveFileName, std::ios::out);
	std::string textLine;

	if (!saveFile.is_open()) {
		std::cerr << "File doesnt exist or failed to open it";
		return;
	}

	while (std::getline(saveFile, textLine)) {
		try {
			const Reservoir loadedGame = Reservoir::deserialize(textLine);

			reservoirAccounting.append(loadedGame);
		}
		catch (std::exception& e) {
			std::cerr << e.what();
		}
	}

	saveFile.close();
}