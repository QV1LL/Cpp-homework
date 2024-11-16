#include <iostream>
#include <string>

#include "GameLibrary.h"
#include "Game.h"

void printColored(std::string_view text, std::string_view color);

auto GameLibrary::add(Game game) -> void {
	this->games.push_back(game);
}

auto GameLibrary::deleteById(int id) -> void {
	if (id < 0 || id >= this->games.size()) {
		std::cerr << "Invalid id of object!\n\n";
		return;
	}

	this->games.erase(this->games.begin() + id);
}

auto GameLibrary::getById(int id) -> Game*{
	if (id < 0 || id >= this->games.size()) {
		std::cerr << "Invalid id of object!\n\n";
		return nullptr;
	}

	return &this->games[id];
}

auto GameLibrary::printGames() -> void {
	int iterable = 0;

	for (Game& game : this->games) {
		printColored("Game " + std::to_string(++iterable) + " stats: {\n\n", "\033[34m");
		game.printStats();
		printColored("}\n\n", "\033[34m");
	}
}