#include <fstream>

#include "DataSaver.h"
#include "ReservoirAccounting.h"
#include "Reservoir.h"

DataSaver* DataSaver::instance = nullptr;

auto DataSaver::getInstance() -> DataSaver* {
	if (DataSaver::instance == nullptr)
		instance = new DataSaver();

	return instance;
}


auto DataSaver::saveData(ReservoirAccounting* reservoirAccounting,
	const std::string& saveFileName) -> void {

	std::ofstream saveFile(saveFileName, std::ios::out);

	if (!saveFile.is_open()) {
		std::cerr << "Something went wrong...";
		return;
	}

	for (Reservoir game : reservoirAccounting->getReservoirs()) {
		saveFile << game.serialize() + "\n";
	}

	saveFile.close();
}