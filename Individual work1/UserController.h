#pragma once

#include "GameLibrary.h"

struct UserController {
private:
	static UserController* instance;
	GameLibrary* gameLibrary;

	std::string savingFileName;

	UserController(GameLibrary* gameLibrary, const std::string& savingFileName);

public:

	static auto getInstance(GameLibrary* gameLibrary, const std::string& savingFileName) -> UserController*;

	auto printGames() -> void;

	auto addGame() -> void;

	auto editGame(int id) -> void;

	auto deleteById(int id) -> void;

	auto save() -> void;
};