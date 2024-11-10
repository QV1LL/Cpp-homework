#pragma once

#include <iostream>
#include <string_view>

static const std::string platformsNames[] = {
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
	std::string title;
	std::string developer = "unknown";
	std::string publisher = "unknown";

	Platform platform = Platform::STEAM;
	int realiseYear = 2000;

	Game(const std::string_view title, const std::string_view developer, int realiseYear);

	auto printStats() -> void;
	auto serialize() -> std::string;
	static auto deserialize(const std::string& serializedObject) -> Game;
};