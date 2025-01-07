#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

#include "json.hpp"
#include "Date.h"

using json = nlohmann::json;

namespace Project {
	int getCurrentYear() {
		auto now = std::chrono::system_clock::now();
		std::time_t now_time = std::chrono::system_clock::to_time_t(now);
		std::tm* localTime = std::localtime(&now_time);

		return 1900 + localTime->tm_year;
	}
}

const int daysCountInMonthes[] = {
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

Project::Date::Date(uint16_t day, uint16_t month, uint16_t year)
{
	if (month == 0 || month > 12 ||
		day == 0 || day > daysCountInMonthes[month] ||
		Project::getCurrentYear() < year)
		throw gcnew System::ArgumentException("Invalid date");

	this->day = day;
	this->month = month;
	this->year = year;
}

Project::Date::Date(const json& serializedObject)
{
	day = serializedObject.at("day").get<uint16_t>();
	month = serializedObject.at("month").get<uint16_t>();
	year = serializedObject.at("year").get<uint16_t>();
}

Project::Date::operator std::string() const 
{
	return std::to_string(this->day) + "." +
		std::to_string(this->month) + "." +
		std::to_string(this->year);
}

json Project::Date::serialize() const
{
	return {
		{"day", this->day},
		{"month", this->month},
		{"year", this->year},
	};
}
