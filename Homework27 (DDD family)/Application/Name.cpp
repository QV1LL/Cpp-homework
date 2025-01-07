#include <iostream>

#include "json.hpp"
#include "Name.h"

using json = nlohmann::json;

Project::Name::Name(const json& serializedObject)
{
	this->firstName = serializedObject.at("first_name").get<std::string>();
	this->lastName = serializedObject.at("last_name").get<std::string>();
}

json Project::Name::serialize() const
{
	return {
		{"first_name", this->firstName},
		{"last_name", this->lastName},
	};
}
