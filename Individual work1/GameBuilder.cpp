#include "GameBuilder.h"

GameBuilder::GameBuilder() {
	this->game = new Game();
}

auto GameBuilder::getProduct() -> Game {
	Game product = *this->game;

	this->reset();

	return product;
}

auto GameBuilder::reset() -> void {
	Game* oldProduct = this->game;

	this->game = new Game();

	delete oldProduct;
}

auto GameBuilder::setTitle(std::string_view title) -> GameBuilder& {
	this->game->title = (title.empty()) ? "unknown" : title;
	return *this;
}

auto GameBuilder::setDeveloper(std::string_view developer) -> GameBuilder& {
	this->game->developer = (developer.empty()) ? "unknown" : developer;
	return *this;
}

auto GameBuilder::setPublisher(std::string_view publisher) -> GameBuilder& {
	this->game->publisher = (publisher.empty()) ? "unknown" : publisher;
	return *this;
}

auto GameBuilder::setPlatform(Platform platform) -> GameBuilder& {
	this->game->platform = platform;
	return *this;
}

auto GameBuilder::setRealiseYear(const int& realiseYear) -> GameBuilder& {
	this->game->realiseYear = realiseYear;
	return *this;
}