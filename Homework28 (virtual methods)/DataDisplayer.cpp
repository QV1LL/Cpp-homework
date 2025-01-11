#include <iostream>
#include <fstream>
#include <string>

#include "DataDisplayer.h"

DataDisplayer* DataDisplayer::instance = nullptr;

DataDisplayer* DataDisplayer::getInstance()
{
	if (DataDisplayer::instance == nullptr)
		DataDisplayer::instance = new DataDisplayer();

	return DataDisplayer::instance;
}

void DataDisplayer::display(const char* path) const
{
	std::ifstream file(path);
	std::string line;

	int lineIterator = 1;

	if (file.is_open())
		while (std::getline(file, line))
			std::cout << std::to_string(lineIterator++) + ":"
			<< line << "\n";
}
