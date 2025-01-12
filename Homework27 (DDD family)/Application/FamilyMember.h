#pragma once

#include "Date.h"
#include "Name.h"
#include "PhoneNumber.h"
#include "Serializable.h"

using json = nlohmann::json;

namespace Project {

	const std::string stringGenders[2] =
	{
		"Male",
		"Female",
	};

	enum class Gender {
		MALE,
		FEMALE,
	};

	class FamilyMember : public ISerializable
	{
	private:

		Name name;
		Date birthDate;
		PhoneNumber phoneNumber;
		Gender gender;

		std::string nationality = "undefined";

	public:

		FamilyMember(const Name& name,
			const Date& birthDate,
			const PhoneNumber phoneNumber,
			Gender sex,
			const std::string& nationality = "undefined")
			: name(name), birthDate(birthDate), gender(sex), phoneNumber(phoneNumber)
		{
			this->setNationality(nationality);
		}

		explicit FamilyMember(const json& serializedObject);

		void setName(const Name& name);
		Name getName() const { return this->name; }

		virtual void setBirthDate(const Date& name);
		Date getBirthDate() const { return this->birthDate; }

		void setPhoneNumber(const PhoneNumber& phoneNumber);
		PhoneNumber getPhoneNumber() const { return this->phoneNumber; }

		void setGender(const Gender& gender) { this->gender = gender; }
		Gender getGender() const { return this->gender; }

		void setNationality(const std::string& nationality);
		std::string getNationality() const { return this->nationality; }

		virtual json serialize() const;
	};
}

