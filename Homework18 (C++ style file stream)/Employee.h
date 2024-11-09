#pragma once

#include <iostream>
#include <string>

const int minEmployeeAge = 16;

struct Employee {
private:
	std::string lastName;
	int age;

public:
	Employee() = default;

	Employee(int age, const std::string& lastName);

	auto setAge(const int& age) -> void;

	auto setLastName(const std::string& lastName) -> void;

	auto getAge() -> int { return this->age; };

	auto getLastName() -> std::string { return this->lastName; };

	auto getSerialized() -> std::string;

	static auto deserialize(std::string& serializedObject) -> Employee*;
};