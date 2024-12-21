#pragma once

#include <iostream>

class NullPointerDereferenceException : public std::runtime_error
{
public:

	NullPointerDereferenceException()
		: std::runtime_error("Attemping to dereference a null pointer")
	{

	}

	explicit NullPointerDereferenceException(const std::string& error)
		: std::runtime_error(error)
	{

	}
};

