#pragma once

class PhoneNumber
{
private:

	std::string number;

public:

	PhoneNumber(const std::string& number);

	auto setNumber(const std::string& number) -> void;
	auto getNumber() const -> std::string { return this->number; };
};

