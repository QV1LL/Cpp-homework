#include "UserController.h"
#include <vector>

UserController* UserController::instance = nullptr;

UserController::UserController(EmployeesAccountingSystem* employeesAccountingSystem) {
	this->employeesAccountingSystem = employeesAccountingSystem;
}

auto UserController::getInstance(EmployeesAccountingSystem* employeesAccountingSystem) -> UserController* {
	if (UserController::instance == nullptr)
		instance = new UserController(employeesAccountingSystem);

	return instance;
}

auto UserController::printEmployees() -> void {
	int employeesIterator = 0;

	for (Employee employee : this->employeesAccountingSystem->employees) {
		std::cout << "Employee " << ++employeesIterator << " ";
		EmployeesAccountingSystem::printEmployeeStats(&employee);
	}
}

auto UserController::hireEmployee() -> void {
	char lastName[64];
	int age = 0;

	std::cout << "Enter new employee last name: ";
	std::cin.getline(lastName, 64);
	
	try {
		std::cout << "Enter new employee age: ";
		std::cin >> age;
	}
	catch (std::exception e) {
		std::cerr << e.what();
	}

	if (age < 16) age = 16;

	Employee* newEmployee = new Employee(age, *(new std::string(lastName)));

	this->employeesAccountingSystem->employees.push_back(*newEmployee);
}

auto UserController::fireEmployee(int id) -> void {
	auto employees = this->employeesAccountingSystem->employees;

	employees.erase(employees.begin() + id);
}

auto UserController::editEmployee(int id) -> void {
	char lastName[64];
	int age = 0;

	std::cout << "Enter new employee " << id << " last name: ";
	std::cin.getline(lastName, 64);

	try {
		std::cout << "Enter new employee " << id << " age: ";
		std::cin >> age;
	}
	catch (std::exception e) {
		std::cerr << e.what();
	}

	if (age < 16) age = 16;

	auto employees = this->employeesAccountingSystem->employees;

	employees[id].setAge(age);
	employees[id].setLastName(lastName);
}