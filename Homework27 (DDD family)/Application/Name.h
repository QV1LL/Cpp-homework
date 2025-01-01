#pragma once

#include "json.hpp"

using json = nlohmann::json;

namespace Project {

	class Name
	{
	private:

		std::string firstName;
		std::string lastName;

	public:

		Name(const std::string& firstName,
			const std::string& lastName) {
			if (lastName.empty() || firstName.empty())
				throw gcnew System::ArgumentException("First or last name cannot be empty!");

			this->firstName = firstName;
			this->lastName = lastName;
		}

		explicit Name(const json& serializedObject);

		operator std::string() const { return this->firstName + " " + this->lastName; }
		std::ostream& operator<<(std::ostream& out) const { return out << std::string(*this); }

		json serialize() const;
	};
}

