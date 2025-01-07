#include <iostream>
#include <algorithm>

#include "json.hpp"
#include "PhoneNumber.h"

using json = nlohmann::json;

Project::PhoneNumber::PhoneNumber(const json& serializedObject)
{
	this->phoneNumber = serializedObject.at("phone_number").get<std::string>();
}

json Project::PhoneNumber::serialize() const
{
	return json{ {"phone_number", this->phoneNumber} };
}
