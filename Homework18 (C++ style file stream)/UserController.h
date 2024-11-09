#pragma once
#include "EmployeesAccountingSystem.h"

struct UserController {
private:
	static UserController* instance;
	EmployeesAccountingSystem* employeesAccountingSystem;

	UserController(EmployeesAccountingSystem* employeesAccountingSystem);

public:

	static auto getInstance(EmployeesAccountingSystem* employeesAccountingSystem) -> UserController*;

	auto printEmployees() -> void;

	auto hireEmployee() -> void;

	auto fireEmployee(int id) -> void;

	auto editEmployee(int id) -> void;
};