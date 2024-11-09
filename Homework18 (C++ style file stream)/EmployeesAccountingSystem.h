#pragma once

#include <vector>
#include <iostream>
#include "Employee.h"

struct EmployeesAccountingSystem {

public:
	std::vector<Employee> employees;

	auto findEmployeeByLastName(const std::string& targetLastName, const int entrance = 0) -> Employee*;

	static auto printEmployeeStats(Employee* pEmployee) -> void;
};