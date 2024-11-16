#pragma once

#include "Game.h"

struct GameBuilder {
private:
	Game* game;

	auto reset() -> void;

public:
	GameBuilder();

	auto getProduct() -> Game;

	auto setTitle(std::string_view title) -> GameBuilder&;
	auto setDeveloper(std::string_view developer) -> GameBuilder&;
	auto setPublisher(std::string_view publisher) -> GameBuilder&;
	auto setPlatform(Platform platform) -> GameBuilder&;
	auto setRealiseYear(const int& realiseYear) -> GameBuilder&;
};