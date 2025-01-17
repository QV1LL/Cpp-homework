#include <iostream>
#include <stdexcept>

#include "NullObjectMethodInvokeException.h"

NullObjectMethodInvokeException::NullObjectMethodInvokeException(const char* description)
{
	if (description == nullptr)
		throw std::invalid_argument("Description is empty");

	this->description = description;
}
