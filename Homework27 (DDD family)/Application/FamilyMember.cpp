#include <iostream>
#include <algorithm>

#include "json.hpp"
#include "FamilyMember.h"

using json = nlohmann::json;

Project::FamilyMember::FamilyMember(const json& serializedObject) 
	: name(serializedObject["name"]), 
	birthDate(serializedObject["birth_date"]),
	phoneNumber(serializedObject["phone_number"])
{
	this->gender = Project::Gender(serializedObject["sex"]);
	this->nationality = serializedObject["nationality"];
}

void Project::FamilyMember::setName(const Name& name)
{
	this->name = name;
}

void Project::FamilyMember::setBirthDate(const Date& birthDate)
{
	this->birthDate = birthDate;
}

void Project::FamilyMember::setPhoneNumber(const PhoneNumber& phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void Project::FamilyMember::setNationality(const std::string& nationality)
{
	if (nationality.empty())
		throw gcnew System::ArgumentNullException("Nationality cannot be null string");

	this->nationality = nationality;
}

json Project::FamilyMember::serialize() const
{
	return {
		{"name", this->name.serialize()},
		{"nationality", this->nationality},
		{"phone_number", this->phoneNumber.serialize()},
		{"sex", this->gender},
		{"birth_date", this->birthDate.serialize()},
	};
}


