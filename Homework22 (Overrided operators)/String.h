#pragma once

class String
{
private:

	char* text;
	static int countOfCreatedInstance;

public:

	static auto getCountOfCreatedInstances() -> const uint16_t { return String::countOfCreatedInstance; }

	String(uint16_t size = 80) : text(new char(size)) { String::countOfCreatedInstance++; }

	String(const char* text);

	auto enter() -> void; 

	auto print() -> const void { std::cout << this->text; }

	auto operator* (const String& other) -> String;

	~String() { this->text = nullptr; }

};

