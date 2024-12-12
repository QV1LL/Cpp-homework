#pragma once

const int dayCountInMounthes[] = {
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
};

class Date
{
private:

	int year;
	int month;
	int day;

public:

	Date(int day, int month, int year);

	auto normalize() -> void;

	auto toDays() const -> int;

    auto toString() -> std::string;

    auto operator+(int days) const->Date;
};

