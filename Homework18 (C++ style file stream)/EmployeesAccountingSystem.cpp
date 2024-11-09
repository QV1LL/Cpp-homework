#include <iostream>
#include <vector>

#include "Employee.h"
#include "EmployeesAccountingSystem.h"

auto EmployeesAccountingSystem::findEmployeeByLastName(const std::string& targetLastName, const int entrance) -> Employee* {
	int currentEntrance = 0;
	
	for (Employee employee : this->employees)
		if (employee.getLastName() == targetLastName) {
			currentEntrance++;

			if (entrance == currentEntrance)
				return &employee;
		}

	return nullptr;
}

auto EmployeesAccountingSystem::printEmployeeStats(Employee* pEmployee) -> void {
	std::cout << "stats " << "{\n\n";
	std::cout << "\tLast name: " << pEmployee->getLastName() << "\n";
	std::cout << "\tAge: " << pEmployee->getAge() << "\n";
	std::cout << "}\n";
}