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

// And here is move constructor, homework 31 :)
String::String(String&& string)
{
	this->text = string.text;
	string.text = nullptr;
}

String::String(const String& string)
{
	this->text = new char[strlen(string.text)];

	for (int i = 0; string.text[i] != '\0'; i++)
		this->text[i] = string.text[i];
}
