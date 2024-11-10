#include <iostream>
#include <vector>

#include "Game.h"
#include "GameLibrary.h"
#include "DataSaver.h"
#include "DataLoader.h"
#include "UserController.h"

const std::string savingFileName = "savings.sav";

int main() {
	GameLibrary gameLibrary;

	DataLoader* dataLoader = DataLoader::getInstance();
	dataLoader->loadData(gameLibrary, savingFileName);

	UserController* userController = UserController::getInstance(&gameLibrary, savingFileName);

	while (true) {
		std::string userChoice;

		std::cout << "Print game list: print," << '\n'
			<< "Add game: add," << '\n'
			<< "Delete game: delete," << '\n'
			<< "Edit game: edit," << '\n'
			<< "To exit: exit." << '\n' << '\n';

		std::cin >> userChoice;
		std::cin.ignore();

		if (userChoice == "print")
			userController->printGames();

		else if (userChoice == "add")
			userController->addGame();

		else if (userChoice == "delete") {
			int id;
			std::cout << "Enter id: ";
			std::cin >> id;

			userController->deleteById(id - 1);
		}

		else if (userChoice == "edit") {
			int id;
			std::cout << "Enter id: ";
			std::cin >> id;

			userController->editGame(id - 1);
		}
		else if (userChoice == "exit")
			break;

		else
			std::cout << "Incorrect input!\n\n";

		userChoice = "";
	}

	userController->save();

	return 0;
}