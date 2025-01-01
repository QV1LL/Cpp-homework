#include <iostream>
#include <algorithm>

#include "json.hpp"
#include "PhoneNumber.h"

using json = nlohmann::json;

Project::PhoneNumber::PhoneNumber(const json& serializedObject)
{
	this->phoneNumber = serializedObject["phone_number"];
}

json Project::PhoneNumber::serialize() const
{
	return { "phone_number", this->phoneNumber };
}
