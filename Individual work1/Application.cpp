#include <iostream>

#include "Apllication.h"

void printColored(std::string_view text, std::string_view color) {
	std::cout << color << text << "\033[0m" << "\n";
}

Application* Application::instance = nullptr;

Application::Application(UserController* userController) {
	this->userController = userController;
}

auto Application::getInstance(UserController* userController) -> Application* {
	if (instance == nullptr)
		instance = new Application(userController);

	return instance;
}

auto Application::start() -> void {
	while (true) {
		std::string userChoice;

		printColored("MENU", "\033[36m");
		std::cout << "\tPrint game list: print," << '\n'
			<< "\tAdd game: add," << '\n'
			<< "\tDelete game: delete," << '\n'
			<< "\tEdit game: edit," << '\n'
			<< "\tSave data: save," << '\n'
			<< "\tTo exit (on exit data saves automatically): exit." << '\n' << '\n';

		std::cin >> userChoice;
		std::cin.ignore();

		if (userChoice == "print")
			this->userController->printGames();

		else if (userChoice == "add")
			this->userController->addGame();

		else if (userChoice == "delete") {
			int id = -1;

			while (true) {
				std::cout << "Enter an id: ";
				std::cin >> id;

				if (std::cin.fail()) {
					printColored("Incorrect value! *_*", "\033[31m");
					std::cin.clear();
					std::cin.ignore('\n');
					continue;
				}

				break;
			}

			this->userController->deleteById(id - 1);
		}

		else if (userChoice == "edit") {
			int id = -1;

			while (true) {
				std::cout << "Enter an id: ";
				std::cin >> id;

				if (std::cin.fail()) {
					printColored("Incorrect value! *_*", "\033[31m");
					std::cin.clear();
					std::cin.ignore('\n');
					continue;
				}

				break;
			}

			this->userController->editGame(id - 1);
		}
		else if (userChoice == "exit")
			break;

		else if (userChoice == "save")
			this->userController->save();

		else
			printColored("Incorrect input! *_*", "\033[31m");
	}

	this->userController->save();
}