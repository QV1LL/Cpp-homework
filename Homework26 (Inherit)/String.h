#pragma once

#include <iostream>

#include "NullPointerDereferenceException.h"

class String
{
protected:

	char* text;
	size_t size;

public:

	String() : text(nullptr), size(0)
	{

	}
	String(const char* text);
	String(const String& other);

	size_t getSize() const { return this->size; }
	void erase();
	bool isCharInString(char symbol);

	String& operator=(const String& other);
	String operator+(const String& other);
	String& operator+=(const String& other);
	bool operator==(const String& other) const;
	bool operator!=(const String& other) const;
	char& operator[] (int index) const;
	operator char* () const { return this->text; }
	friend std::ostream& operator<<(std::ostream& out, const String& str);

	~String() { this->erase(); }
};