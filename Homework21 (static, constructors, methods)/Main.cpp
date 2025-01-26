#include <iostream>
#include <string>
#include <vector>

#include "String.h"

int main() {
	std::vector<String> myStrings;
	myStrings.push_back("Starii");
	myStrings.push_back("Bog");

	std::cout << String::getCountOfCreatedInstances();

	String myString = String();
	myString.enter();

	String other{ std::move(myString) };
	std::cout << "My String: ";
	myString.print();
	std::cout << '\n';

	myStrings.push_back(other);

	for (String string : myStrings) {
		string.print();
	}
}