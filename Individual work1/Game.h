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
public:
	std::string title = "unknown";
	std::string developer = "unknown";
	std::string publisher = "unknown";

	Platform platform = Platform::STEAM;
	int realiseYear = 2000;

	Game() = default;

	auto printStats() -> void;
	auto serialize() -> std::string;
	static auto deserialize(const std::string& serializedObject) -> Game;
};