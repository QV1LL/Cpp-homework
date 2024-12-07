#include <iostream>
#include <string>

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