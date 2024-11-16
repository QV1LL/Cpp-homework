#pragma once

#include <iostream>
#include <string_view>
#include <vector>

static const std::vector<std::string> platformsNames = {
	"Steam",
	"Epic games",
	"Origin",
};

enum class Platform {
	STEAM,
	EPIC_GAMES,
	ORIGIN,
};

struct Game {
private:
	std::string title = "unknown";
	std::string developer = "unknown";
	std::string publisher = "unknown";

	Platform platform = Platform::STEAM;
	int realiseYear = 2000;

public:
	Game() = default;

	auto printStats() -> void;
	auto serialize() -> std::string;
	static auto deserialize(const std::string& serializedObject) -> Game;

	friend struct UserController;
	friend struct GameBuilder;
};