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

	myStrings.push_back(myString);

	for (String string : myStrings) {
		string.print();
	}
}