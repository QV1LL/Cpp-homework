#include <iostream>
#include <algorithm>

#include "FamilyMember.h"
#include "json.hpp"

using json = nlohmann::json;

Project::FamilyMember::FamilyMember(json serializedObject)
{
	throw gcnew System::NotImplementedException("I dont know how to do this yet ;(");
}

json Project::FamilyMember::serialize()
{
	return {
		{"name", this->name},
		{"nationality", this->nationality},
		{"phone_number", this->phoneNumber},
		{"sex", this->sex},
		{"birth_date", this->birthDate},
	};
}
