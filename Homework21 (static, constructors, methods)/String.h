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
	// And here is move constructor, homework 31 :)
	String(String&& string);
	String(const String& string);

	auto enter() -> void; 
	auto print() -> const void { if (text) std::cout << this->text; }

	~String() {
		delete[] this->text;
		this->text = nullptr; 
	}

};

