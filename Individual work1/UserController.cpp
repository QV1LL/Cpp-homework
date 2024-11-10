#include <vector>

#include "UserController.h"
#include "DataSaver.h"

UserController* UserController::instance = nullptr;

UserController::UserController(GameLibrary* gameLibrary, const std::string& savingFileName) {
	this->gameLibrary = gameLibrary;
	this->savingFileName = savingFileName;
}

auto UserController::getInstance(GameLibrary* gameLibrary, const std::string& savingFileName) -> UserController* {
	if (UserController::instance == nullptr)
		instance = new UserController(gameLibrary, savingFileName);

	return instance;
}

auto UserController::printGames() -> void {
	this->gameLibrary->printGames();
}

auto UserController::addGame() -> void {
	char title[64];
	char developer[64];
	int realiseYear;

	std::cout << "Enter title: ";
	std::cin.getline(title, 64);
	std::cin.ignore();

	std::cout << "Enter developer: ";
	std::cin.getline(developer, 64);
	std::cin.ignore();

	std::cout << "Enter realise year: ";
	std::cin >> realiseYear;

	Game game{title, developer, realiseYear};

	this->gameLibrary->add(game);
}

auto UserController::deleteById(int id) -> void {
	this->gameLibrary->deleteById(id);
}

auto UserController::editGame(int id) -> void {
	char title[64]{ 0 };
	char developer[64]{ 0 };
	char publisher[64]{ 0 };
	char stringPlatform[64]{ 0 };
	int realiseYear = 1980;

	std::cout << "Enter game " << id + 1 << " title: ";
	std::cin.ignore();
	std::cin.getline(title, 64);

	std::cout << "Enter game " << id + 1 << " developer: ";
	std::cin.getline(developer, 64);

	std::cout << "Enter game " << id + 1 << " publisher: ";
	std::cin.getline(publisher, 64);

	std::cout << "Enter game " << id + 1 << " online platform: ";
	std::cin.getline(stringPlatform, 64);

	Platform platform = (Platform)((int)platforms->find(stringPlatform));

	std::cout << "Enter game " << id + 1 << " realiseYear: ";
	std::cin >> realiseYear;

	if (realiseYear < 1980) realiseYear = 1980;

	this->gameLibrary->games[id].title = title;
	this->gameLibrary->games[id].developer = developer;
	this->gameLibrary->games[id].publisher = publisher;
	this->gameLibrary->games[id].platform = platform;
	this->gameLibrary->games[id].realiseYear = realiseYear;
}

auto UserController::save() -> void {
	DataSaver* dataSaver = DataSaver::getInstance();
	dataSaver->saveData(this->gameLibrary, this->savingFileName);
}