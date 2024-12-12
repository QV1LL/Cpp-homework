#include <iostream>
#include <cmath>
#include <string>

#include "Date.h"

Date::Date(int day, int month, int year) {
	if (0 > year || (0 > month || month > 12) || (0 > day > dayCountInMounthes[month]))
		throw std::invalid_argument("Invalid object params...");

	this->day = day;
	this->month = month;
	this->year = year;
}

auto Date::normalize() -> void {
	if (this->day > dayCountInMounthes[this->month - 1]) {
		this->day -= dayCountInMounthes[this->month - 1];
		this->month++;
		this->normalize();
	}

	if (this->month > 12) {
		this->year++;
		this->month -= 12;
		this->normalize();
	}
}

auto Date::toDays() const -> int {
	int totalDays = 0;
	totalDays += year * 365;

	for (int i = 1; i < month; ++i)
		totalDays += dayCountInMounthes[i];

	totalDays += day;

	return totalDays;
}

auto Date::operator+(int days) const -> Date {
	Date result(*this);

	result.day += days;
	result.normalize();

	return result;
}

auto Date::toString() -> std::string {
	return std::to_string(this->day) + '.' +
		std::to_string(this->month) + '.' +
		std::to_string(this->year);
}

auto operator-(Date& date1, Date& date2) -> int {
	int totalDaysFromDate1 = date1.toDays();
	int totalDaysFromDate2 = date2.toDays();

	return std::abs(totalDaysFromDate1 - totalDaysFromDate2);
}