#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>

#include "Game.h"
#include "GameBuilder.h"

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

auto Game::printStats() -> void {
	std::cout << "\tGame: " << this->title << '\n'
		<< "\tDeveloper: " << this->developer << '\n'
		<< "\tPublisher: " << this->publisher << '\n'
		<< "\tOnline platform: " << platformsNames[(int)this->platform] << '\n'
		<< "\tRealise: " << this->realiseYear << '\n';
}

auto Game::serialize() -> std::string {
	return this->title + "$"
		+ this->developer + "$"
		+ this->publisher + "$"
		+ std::to_string(this->realiseYear) + "$"
		+ platformsNames[(int)this->platform];
}

auto Game::deserialize(const std::string& serializedObject) -> Game {
	auto serializedParts = split(serializedObject, '$');

	GameBuilder* gameBuilder = new GameBuilder();
	gameBuilder->setTitle(serializedParts[0])
		.setDeveloper(serializedParts[1])
		.setPublisher(serializedParts[2])
		.setRealiseYear(std::stoi(serializedParts[3]))
		.setPlatform((Platform)std::distance(platformsNames.begin(), std::find(platformsNames.begin(), platformsNames.end(), serializedParts[4])));

	return gameBuilder->getProduct();
}