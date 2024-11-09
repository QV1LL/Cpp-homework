#include <iostream>
#include <string>

#include "Employee.h"
#include "EmployeesAccountingSystem.h"
#include "DataSaver.h"
#include "DataLoader.h"
#include "UserController.h"

const std::string savingFileName = "employeers.sav";

auto save(EmployeesAccountingSystem* employeesAccountingSystem) -> void {
	DataSaver* dataSaver = DataSaver::getInstance();
	dataSaver->saveData(*employeesAccountingSystem, savingFileName);
}

int main() {
	EmployeesAccountingSystem* employeesAccountingSystem = new EmployeesAccountingSystem();

	DataLoader* dataLoader = DataLoader::getInstance();
	dataLoader->loadData(*employeesAccountingSystem, savingFileName);

	UserController* userController = UserController::getInstance(employeesAccountingSystem);


	while (true) {
		std::string userChoice;

		std::cout << "Print workers list: print," << '\n'
			<< "Hire employee: hire," << '\n'
			<< "Fire employee: fire," << '\n'
			<< "Edit employee: edit," << '\n'
			<< "To exit: exit." << '\n';

		std::cin >> userChoice;

		if (userChoice == "print")
			userController->printEmployees();

		else if (userChoice == "hire")
			userController->hireEmployee();

		else if (userChoice == "fire") {
			int id;
			std::cout << "Enter id: ";
			std::cin >> id;

			userController->fireEmployee(id);
		}

		else if (userChoice == "edit") {
			int id;
			std::cout << "Enter id: ";
			std::cin >> id;

			userController->editEmployee(id);
		}
		else if (userChoice == "exit")
			break;

		else
			std::cout << "Incorrect input!'\n";
	}
	

	save(employeesAccountingSystem);
}