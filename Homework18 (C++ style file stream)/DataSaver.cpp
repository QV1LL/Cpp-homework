#include "DataSaver.h"
#include "Employee.h"
#include <fstream>

DataSaver* DataSaver::instance = nullptr;

auto DataSaver::getInstance() -> DataSaver* {
	if (DataSaver::instance == nullptr)
		instance = new DataSaver();

	return instance;
}


auto DataSaver::saveData(const EmployeesAccountingSystem& employeesAccountingSystem, 
	const std::string& saveFileName) -> void {

	std::ofstream saveFile(saveFileName, std::ios::out);

	if (!saveFile.is_open()) {
		std::cerr << "Something went wrong...";
		return;
	}

	for (Employee employee : employeesAccountingSystem.employees) {
		saveFile << employee.getSerialized() + "\n";
	}

	saveFile.close();
}