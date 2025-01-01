#pragma once

#include <algorithm>

#include "json.hpp"

using json = nlohmann::json;

namespace Project {

	class PhoneNumber
	{
	private:

		std::string phoneNumber;

	public:

		PhoneNumber(const std::string& phoneNumber) {
			if (phoneNumber.length() != 10 || !std::all_of(phoneNumber.begin(), phoneNumber.end(), [] (unsigned char symbol) { return std::isdigit(symbol); }))
				throw gcnew System::ArgumentException("Phone number must be string that containts 10 digits!");

			this->phoneNumber = phoneNumber;
		}

		explicit PhoneNumber(const json& serializedObject);

		operator std::string() const { return "+38" + this->phoneNumber; }
		std::ostream& operator<<(std::ostream& out) const { return out << std::string(*this); }

		json serialize() const;
	};
}

