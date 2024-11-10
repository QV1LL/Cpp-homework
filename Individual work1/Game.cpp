#include <iostream>
#include <string>
#include <string_view>
#include <vector>

#include "Game.h"

auto split(const std::string& str, char delimiter) -> std::vector<std::string> {
	std::vector<std::string> tokens;
	size_t start = 0;
	size_t end = str.find(delimiter);

	while (end != std::string::npos) {
		tokens.push_back(str.substr(start, end - start));
		start = end + 1;
		end = str.find(delimiter, start);
	}

	tokens.push_back(str.substr(start));
	return tokens;
}

Game::Game(const std::string_view title, const std::string_view developer, int realiseYear) {
	this->title = (!title.empty()) ? title : "unknown";
	this->developer = (!developer.empty()) ? developer : "unknown";
	this->realiseYear = (realiseYear >= 1980) ? realiseYear : 1980;
}

auto Game::printStats() -> void {
	std::cout << "\tGame: " << this->title << '\n'
		<< "\tDeveloper: " << this->developer << '\n'
		<< "\tPublisher: " << this->publisher << '\n'
		<< "\tOnline platform: " << platforms[(int)this->platform] << '\n'
		<< "\tRealise: " << this->realiseYear << '\n';
}

auto Game::getSerialized() -> std::string {
	return this->title + "$"
		+ this->developer + "$"
		+ this->publisher + "$"
		+ std::to_string(this->realiseYear) + "$"
		+ platforms[(int)this->platform];
}

auto Game::deserialize(const std::string& serializedObject) -> Game {
	auto serializedParts = split(serializedObject, '$');

	Game deserializedGame(serializedParts[0],
		serializedParts[1],
		std::stoi(serializedParts[3]));

	deserializedGame.publisher = serializedParts[2];
	deserializedGame.platform = (Platform)platforms->find(serializedParts[4]);

	return deserializedGame;
}