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
	char lastName[64]{0};
	int age = 0;

	std::cout << "Enter new employee last name: ";
	std::cin.ignore();
	std::cin.getline(lastName, 64);

	std::cout << "Enter new employee age: ";
	std::cin >> age;

	if (age < 16) age = 16;

	Employee* newEmployee = new Employee(age, *(new std::string((lastName[0] != 0) ? lastName : "employee")));

	this->employeesAccountingSystem->employees.push_back(*newEmployee);
}

auto UserController::fireEmployee(int id) -> void {
	if (id >= employeesAccountingSystem->employees.size() || id < 0) return;

	this->employeesAccountingSystem->employees.erase(this->employeesAccountingSystem->employees.begin() + id);
}

auto UserController::editEmployee(int id) -> void {
	if (id >= employeesAccountingSystem->employees.size() || id < 0) return;
	
	char lastName[64]{0};
	int age = 0;

	std::cout << "Enter employee " << id + 1 << " last name: ";
	std::cin.ignore();
	std::cin.getline(lastName, 64);

	std::cout << "Enter employee " << id + 1 << " age: ";
	std::cin >> age;

	if (age < 16) age = 16;

	this->employeesAccountingSystem->employees[id].setAge(age);
	this->employeesAccountingSystem->employees[id].setLastName((lastName[0] != 0) ? lastName : "employee");
}