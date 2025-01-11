#include <iostream>

#include "DataDisplayer.h"
#include "ASCIIDataDisplayer.h"
#include "BinaryDataDisplayer.h"

int main()
{
	DataDisplayer::getInstance()->display("text.txt");
	std::cout << '\n';
	ASCIIDataDisplayer::getInstance()->display("text.txt");
	std::cout << '\n';
	BinaryDataDisplayer::getInstance()->display("text.txt");
}