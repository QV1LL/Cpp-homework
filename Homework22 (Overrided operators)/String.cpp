#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include "String.h"

int String::countOfCreatedInstance = 0;

String::String(const char* text) {
	if (text == nullptr)
		throw std::invalid_argument("Parameter is nullptr object.");
	
	this->text = new char[strlen(text) + 1];
	strcpy_s(this->text, strlen(text) + 1, text);
	String::countOfCreatedInstance++;
}

auto String::enter() -> void {
	std::cout << "\n";
	char inputText[1024];
	std::cin.getline(inputText, sizeof(inputText));

	delete this->text;
	this->text = new char[strlen(text) + 1];
	strcpy_s(this->text, strlen(inputText) + 1, inputText);

	String::countOfCreatedInstance++;
}

auto String::operator* (const String& other) -> String {
	std::string sorted1 = this->text;
	std::string sorted2 = other.text;
	std::sort(sorted1.begin(), sorted1.end());
	std::sort(sorted2.begin(), sorted2.end());

	// Step 2: Use set_intersection
	std::string result;
	std::set_intersection(
		sorted1.begin(), sorted1.end(), // Range for the first string
		sorted2.begin(), sorted2.end(), // Range for the second string
		std::back_inserter(result)      // Output iterator for the result
	);

	return String(result.c_str());
}