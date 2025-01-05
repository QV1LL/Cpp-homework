#pragma once

#include "json.hpp"

using json = nlohmann::json;

namespace Project {

	int getCurrentYear();

	class Date
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

		uint16_t getYear() const { return this->year; }

		operator std::string() const;
		std::ostream& operator<<(std::ostream& out) const { return out << std::string(*this); }

		json serialize() const;
	};
}

