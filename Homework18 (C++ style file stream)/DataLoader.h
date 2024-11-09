#pragma once

#include <iostream>
#include "EmployeesAccountingSystem.h"

struct DataLoader {
private:
	static DataLoader* instance;

	DataLoader() = default;

public:

	auto loadData(EmployeesAccountingSystem& employeesAccountingSystem,
		const std::string& saveFileName) -> void;

	static auto getInstance() -> DataLoader*;
};