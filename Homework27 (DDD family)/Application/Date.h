#pragma once

#include "json.hpp"

using json = nlohmann::json;

namespace Project {

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

		operator std::string() const;
		std::ostream& operator<<(std::ostream& out) const { return out << std::string(*this); }

		json serialize() const;
	};
}

