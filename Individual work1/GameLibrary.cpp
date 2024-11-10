#include <iostream>

#include "GameLibrary.h"
#include "Game.h"

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
		std::cout << "Game " << ++iterable <<" stats: {\n\n";
		game.printStats();
		std::cout << "}\n\n";
	}
}