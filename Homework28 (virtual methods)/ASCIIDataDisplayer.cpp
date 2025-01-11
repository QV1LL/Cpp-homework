#include <iostream>
#include <fstream>
#include <string>

#include "DataDisplayer.h"
#include "ASCIIDataDisplayer.h"

ASCIIDataDisplayer* ASCIIDataDisplayer::instance = nullptr;

ASCIIDataDisplayer* ASCIIDataDisplayer::getInstance()
{
	if (ASCIIDataDisplayer::instance == nullptr)
		ASCIIDataDisplayer::instance = new ASCIIDataDisplayer();

	return ASCIIDataDisplayer::instance;
}

void ASCIIDataDisplayer::display(const char* path) const
{
	std::ifstream file(path);
	std::string line;

	int lineIterator = 1;

	if (file.is_open())
		while (std::getline(file, line))
		{
			std::cout << std::to_string(lineIterator++) + ":";
			for (const char& symbol : line)
				std::cout << int(symbol) << " ";
			std::cout << '\n';
		}

}
