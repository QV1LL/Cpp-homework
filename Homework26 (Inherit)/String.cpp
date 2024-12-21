#include <cstring>

#include "String.h"

String::String(const char* text = "")
{
    if (text == nullptr)
        throw NullPointerDereferenceException();

    this->size = strlen(text) + 1;
    this->text = new char[1024];
    strcpy_s(this->text, this->size, text);
}

String::String(const String& other)
{
    this->size = other.size;
    this->text = new char[1024];
    strcpy_s(this->text, this->size, other.text);
}

void String::erase()
{
    if (this->text != nullptr) {
        delete[] this->text;
        this->text = nullptr;
    }

    this->size = 0;
}

bool String::isCharInString(char symbol)
{
    return (std::find(this->text, this->text + this->size, symbol) != this->text + this->size);
}

String& String::operator=(const String& other)
{
	this->erase();

	*this = String(other);

	return *this;
}

String String::operator+(const String& other)
{
	strcat_s(this->text, this->size + other.size, other.text);

	return String(this->text);
}

String& String::operator+=(const String& other)
{
	strcat_s(this->text, this->size + other.size, other.text);

	return *this;
}

bool String::operator==(const String& other) const
{
	return strcmp(this->text, other.text) == 0;
}

bool String::operator!=(const String& other) const
{
	return !(*this == other);
}

char& String::operator[] (int index) const
{
    if (index < 0 || index >= this->size)
        throw std::out_of_range("Index was out of bounds");

    return this->text[index];
}

std::ostream& operator<<(std::ostream& out, const String& string) { return out << string.text; }


