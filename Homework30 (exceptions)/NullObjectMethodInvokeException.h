#pragma once
class NullObjectMethodInvokeException : std::exception
{
private:

	const char* description;

public:

	explicit NullObjectMethodInvokeException(const char* desctiption);

	virtual char const* what() const override { return this->description; }
};

