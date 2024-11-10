#pragma once

#include <vector>
#include "Game.h"

struct GameLibrary {
private:
	std::vector<Game> games;

public:

	GameLibrary() = default;

	auto add(Game game) -> void;
	auto deleteById(int id) -> void;
	auto getById(int id) -> Game*;
	auto printGames() -> void;

	friend struct DataSaver;
	friend struct UserController;
};