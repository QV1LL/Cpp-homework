#pragma once

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

		operator std::string() const;
		std::ostream& operator<<(std::ostream& out) const { return out << std::string(*this); }
	};
}

