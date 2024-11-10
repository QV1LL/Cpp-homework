#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "DataLoader.h"
#include "Game.h"
#include "GameLibrary.h"

DataLoader* DataLoader::instance = nullptr;

auto DataLoader::getInstance() -> DataLoader* {
	if (DataLoader::instance == nullptr)
		instance = new DataLoader();

	return instance;
}


auto DataLoader::loadData(GameLibrary& gameLibrary,
	const std::string& saveFileName) -> void {

	std::ifstream saveFile(saveFileName, std::ios::out);
	std::string textLine;

	if (!saveFile.is_open()) {
		std::cerr << "File doesnt exist or failed to open it";
		return;
	}

	while (std::getline(saveFile, textLine)) {
		try {
			const Game loadedGame = Game::deserialize(textLine);

			gameLibrary.add(loadedGame);
		}
		catch (std::exception& e) {
			std::cerr << e.what();
		}
	}

	saveFile.close();
}