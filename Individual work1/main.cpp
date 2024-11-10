#include <iostream>
#include <vector>

#include "Game.h"
#include "GameLibrary.h"
#include "DataSaver.h"
#include "DataLoader.h"
#include "UserController.h"
#include "Apllication.h"

const std::string savingFileName = "savings.sav";

int main() {
	GameLibrary gameLibrary;

	DataLoader* dataLoader = DataLoader::getInstance();
	dataLoader->loadData(gameLibrary, savingFileName);

	UserController* userController = UserController::getInstance(&gameLibrary, savingFileName);
	Application* application = Application::getInstance(userController);
	
	application->start();

	return 0;
}