#include <iostream>

#include "json.hpp"
#include "Name.h"

using json = nlohmann::json;

Project::Name::Name(const json& serializedObject)
{
	this->firstName = serializedObject["first_name"];
	this->lastName = serializedObject["last_name"];
}

json Project::Name::serialize() const
{
	return {
		{"first_name", this->firstName},
		{"last_name", this->lastName},
	};
}
