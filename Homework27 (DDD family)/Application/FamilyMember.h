#pragma once

#include "Date.h"
#include "Name.h"
#include "PhoneNumber.h"

namespace Project {

	enum class Sex {
		MALE,
		FEMALE,
		PANZERKAUMPFWAGEN,
	};

	class FamilyMember
	{
	private:

		Name name;
		Date birthDate;
		PhoneNumber phoneNumber;
		Sex sex;

		std::string nationality = "undefined";

	public:

		FamilyMember(const Name& name,
			const Date& birthDate,
			const PhoneNumber phoneNumber,
			Sex sex,
			const std::string& nationality = "undefined")
			: name(name), birthDate(birthDate), sex(sex), phoneNumber(phoneNumber)
		{
			if (!nationality.empty())
				this->nationality = nationality;
		}

		Name getName() const { return this->name; }
		Date getBirthDate() const { return this->birthDate; }
		PhoneNumber getPhoneNumber() const { return this->phoneNumber; }
		std::string getNationality() const { return this->nationality; }

	};
}

