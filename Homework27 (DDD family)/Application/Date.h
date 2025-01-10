#pragma once

#include "json.hpp"
#include "Serializable.h"

using json = nlohmann::json;

namespace Project {

	int getCurrentYear();

	class Date : public Serializable
	{
	private:

		uint16_t day;
		uint16_t month;
		uint16_t year;

	public:

		Date(uint16_t day,
		uint16_t month,
		uint16_t year);

		explicit Date(const json& serializedObject);

		uint16_t getDay() const { return this->day; }
		uint16_t getMonth() const { return this->month; }
		uint16_t getYear() const { return this->year; }

		operator std::string() const;
		std::ostream& operator<<(std::ostream& out) const { return out << std::string(*this); }

		virtual json serialize() const;
	};
}

