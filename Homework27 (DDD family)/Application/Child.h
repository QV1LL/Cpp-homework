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
			Gender gender,
			const std::string& educationPlace = "missing",
			const std::string& nationality = "undefined")
			: FamilyMember(name, birthDate, phoneNumber, gender, nationality)
		{
			this->setEducationPlace(educationPlace);
		}

		explicit Child(const json& serializedObject);

		void setEducationPlace(const std::string& educationPlace);
		std::string getEducationPlaceTitle() const { return this->educationPlace; }

		json serialize() const override;
	};
}

