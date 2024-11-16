#include <vector>

#include "UserController.h"
#include "DataSaver.h"
#include "GameBuilder.h"

void printColored(std::string_view text, std::string_view color);

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

	std::cout << "Enter developer: ";
	std::cin.getline(developer, 64);

	while (true) {
		std::cout << "Enter game realiseYear: ";
		std::cin >> realiseYear;

		if (std::cin.fail()) {
			printColored("Incorrect value! *_*", "\033[31m");
			std::cin.clear();
			std::cin.ignore('\n');
			continue;
		}

		break;
	}

	GameBuilder* gameBuilder = new GameBuilder();
	gameBuilder->setTitle(title)
		.setDeveloper(developer)
		.setRealiseYear(realiseYear);

	this->gameLibrary->add(gameBuilder->getProduct());

	std::cout << "\t" << title << " added!\n" << '\n';
}

auto UserController::deleteById(int id) -> void {
	if (id < 0 || this->gameLibrary->games.size() <= id) {
		printColored("Incorrect id! *_*", "\033[31m");
		return;
	}
	
	std::string removedTitle = this->gameLibrary->games[id].title;
	this->gameLibrary->deleteById(id);

	std::cout << removedTitle << " removed!\n" << '\n';
}

auto UserController::editGame(int id) -> void {
	if (id < 0 || this->gameLibrary->games.size() <= id) {
		printColored("Incorrect id! *_*", "\033[31m");
		return;
	}

	while (true) {
		std::string userChoice;

		printColored("EDIT MODE", "\033[36m");
		std::cout << "\tEdit title: title," << '\n'
			<< "\tEdit developer: developer," << '\n'
			<< "\tEdit publisher: publisher," << '\n'
			<< "\tEdit platform: platform," << '\n'
			<< "\tEdit realise year: year." << '\n'
			<< "\tExit from edit mode: exit." << '\n';

		std::cin >> userChoice;
		std::cin.ignore();

		if (userChoice == "title") {
			char title[64]{ 0 };

			std::cout << "Enter game " << id + 1 << " title: ";
			std::cin.getline(title, 64);

			this->gameLibrary->games[id].title = title;
		}
		else if (userChoice == "developer") {
			char developer[64]{ 0 };

			std::cout << "Enter game " << id + 1 << " developer: ";
			std::cin.getline(developer, 64);

			this->gameLibrary->games[id].developer = developer;
		}
		else if (userChoice == "publisher") {
			char publisher[64]{ 0 };

			std::cout << "Enter game " << id + 1 << " publisher: ";
			std::cin.getline(publisher, 64);

			this->gameLibrary->games[id].publisher = publisher;
		}
		else if (userChoice == "platform") {
			char stringPlatform[64]{ 0 };

			std::cout << "Enter game " << id + 1 << " online platform: ";
			std::cin.getline(stringPlatform, 64);

			int platformIndex = -1;
			for (int i = 0; i < platformsNames.size(); i++) {
				if (strcmp(platformsNames[i].c_str(), stringPlatform) == 0) {
					platformIndex = i;
					break;
				}
			}

			Platform platform = static_cast<Platform>(platformIndex);


			this->gameLibrary->games[id].platform = (platformIndex != -1) ?
				platform : this->gameLibrary->games[id].platform;
		}
		else if (userChoice == "year") {
			int realiseYear;

			while (true) {
				std::cout << "Enter game " << id + 1 << " realiseYear: ";
				std::cin >> realiseYear;

				if (std::cin.fail()) {
					printColored("Incorrect value! *_*", "\033[31m");
					std::cin.clear();
					std::cin.ignore('\n');
					continue;
				}

				break;
			}

			this->gameLibrary->games[id].realiseYear = (realiseYear < 1980) ?
				this->gameLibrary->games[id].realiseYear : realiseYear;
		}
		else if (userChoice == "exit")
			break;
		else
			printColored("Incorrect input! *_*", "\033[31m");
	}
}

auto UserController::save() -> void {
	DataSaver* dataSaver = DataSaver::getInstance();
	dataSaver->saveData(this->gameLibrary, this->savingFileName);
	
	printColored("\tSaving data... -_-", "\033[32m");
	printColored("\tData saved!\n", "\033[32m");
}