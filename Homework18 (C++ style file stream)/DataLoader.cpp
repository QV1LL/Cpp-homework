#include "DataLoader.h"
#include "Employee.h"
#include <vector>
#include <fstream>

DataLoader* DataLoader::instance = nullptr;

auto DataLoader::getInstance() -> DataLoader* {
	if (DataLoader::instance == nullptr)
		instance = new DataLoader();

	return instance;
}


auto DataLoader::loadData(EmployeesAccountingSystem& employeesAccountingSystem,
	const std::string& saveFileName) -> void {

	std::ifstream saveFile(saveFileName, std::ios::out);
	std::string textLine;

	if (!saveFile.is_open()) {
		std::cerr << "File doesnt exist or failed to open it";
		return;
	}

	while (std::getline(saveFile, textLine)) {
		try {
			const Employee* loadedEmployee = Employee::deserialize(textLine);

			employeesAccountingSystem.employees.push_back(*loadedEmployee);
		}
		catch (std::exception& e) {
			std::cerr << e.what();
		}
	}

	saveFile.close();
}