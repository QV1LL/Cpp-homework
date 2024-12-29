#pragma once

#include "FamilyMember.h"

namespace Project {
	
	class Child : public FamilyMember
	{
	private:

		std::string educationPlace;

	public:

		Child(const Name& name,
			const Date& birthDate,
			const PhoneNumber phoneNumber,
			Sex sex,
			const std::string& educationPlace = "missing",
			const std::string& nationality = "undefined")
			: FamilyMember(name, birthDate, phoneNumber, sex, nationality)
		{
			if (!educationPlace.empty())
				this->educationPlace = educationPlace;
		}

		std::string getEducationPlaceTitle() const { return this->educationPlace; }
	};
}

