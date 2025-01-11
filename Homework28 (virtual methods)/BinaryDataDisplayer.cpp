#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

#include "DataDisplayer.h"
#include "ASCIIDataDisplayer.h"
#include "BinaryDataDisplayer.h"

BinaryDataDisplayer* BinaryDataDisplayer::instance = nullptr;

BinaryDataDisplayer* BinaryDataDisplayer::getInstance()
{
	if (BinaryDataDisplayer::instance == nullptr)
		BinaryDataDisplayer::instance = new BinaryDataDisplayer();

	return BinaryDataDisplayer::instance;
}

void BinaryDataDisplayer::display(const char* path) const
{
	std::ifstream file(path);
	std::string line;

	int lineIterator = 1;

	if (file.is_open())
		while (std::getline(file, line))
		{
			std::cout << std::to_string(lineIterator++) + ":";
			for (const char& symbol : line)
				std::cout << std::bitset<8>(symbol).to_string() << " ";
			std::cout << '\n';
		}

}
