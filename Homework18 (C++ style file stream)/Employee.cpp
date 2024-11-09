#include <iostream>

#include "Employee.h"

Employee::Employee(int age, const std::string& lastName) {
	this->setAge(age);
	this->setLastName(lastName);
}

auto Employee::setAge(const int& age) -> void {
	if (age >= minEmployeeAge)
		this->age = age;
}

auto Employee::setLastName(const std::string& lastName) -> void {
	if (!lastName.empty())
		this->lastName = lastName;
}

auto Employee::getSerialized() -> std::string {
	return this->lastName + "$" + std::to_string(this->age);
}

auto Employee::deserialize(std::string& serializedObject) -> Employee* {
	std::string lastName = serializedObject.substr(0, serializedObject.find("$"));
	int age = std::stoi(serializedObject.substr(serializedObject.find("$") + 1, serializedObject.size() - serializedObject.find("$") + 1));

	return new Employee(age, lastName);
}