#include <fstream>

#include "DataSaver.h"
#include "GameLibrary.h"
#include "Game.h"

DataSaver* DataSaver::instance = nullptr;

auto DataSaver::getInstance() -> DataSaver* {
	if (DataSaver::instance == nullptr)
		instance = new DataSaver();

	return instance;
}


auto DataSaver::saveData(GameLibrary* gameLibrary,
	const std::string& saveFileName) -> void {

	std::ofstream saveFile(saveFileName, std::ios::out);

	if (!saveFile.is_open()) {
		std::cerr << "Something went wrong...";
		return;
	}

	for (Game game : gameLibrary->games) {
		saveFile << game.serialize() + "\n";
	}

	saveFile.close();
}