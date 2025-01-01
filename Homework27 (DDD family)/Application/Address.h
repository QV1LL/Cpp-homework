#pragma once

#include "json.hpp"

using json = nlohmann::json;

namespace Project {

	class Address
	{
	private:

		std::string town;
		std::string street;
		uint16_t buildingNumber;
		uint16_t flatNumber;

	public:

		Address(const std::string& town,
			const std::string& street,
			uint16_t buildingNumber,
			uint16_t flatNumber) {
			if (town.empty() || street.empty() || buildingNumber == 0)
				throw gcnew System::ArgumentException("Invalid arguments passed to address!");

			this->town = town;
			this->street = street;
			this->buildingNumber = buildingNumber;
			this->flatNumber = flatNumber;
		}

		explicit Address(const json& serializedObject);

		operator std::string() const;
		std::ostream& operator<<(std::ostream& out) const;

		json serialize() const;
	};
}

