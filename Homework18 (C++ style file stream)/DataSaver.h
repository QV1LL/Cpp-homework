#pragma once

#include <iostream>
#include "EmployeesAccountingSystem.h"

struct DataSaver {
private:
	static DataSaver* instance;

	DataSaver() = default;

public:

	auto saveData(const EmployeesAccountingSystem& employeesAccountingSystem, 
		const std::string& saveFileName) -> void;

	static auto getInstance() -> DataSaver*;
};