#include <iostream>

#include "Apllication.h"

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

		std::cout << "MENU: \n";
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
			int id;
			std::cout << "Enter id: ";
			std::cin >> id;

			this->userController->deleteById(id - 1);
		}

		else if (userChoice == "edit") {
			int id;
			std::cout << "Enter id: ";
			std::cin >> id;

			this->userController->editGame(id - 1);
		}
		else if (userChoice == "exit")
			break;

		else if (userChoice == "save")
			this->userController->save();

		else
			std::cerr << "\tIncorrect input! *_*\n\n";

		userChoice = "";
	}

	this->userController->save();
}