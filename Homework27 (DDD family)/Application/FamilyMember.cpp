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
	this->sex = Project::Sex(serializedObject["sex"]);
	this->nationality = serializedObject["nationality"];
}

json Project::FamilyMember::serialize() const
{
	return {
		{"name", this->name.serialize()},
		{"nationality", this->nationality},
		{"phone_number", this->phoneNumber.serialize()},
		{"sex", this->sex},
		{"birth_date", this->birthDate.serialize()},
	};
}


