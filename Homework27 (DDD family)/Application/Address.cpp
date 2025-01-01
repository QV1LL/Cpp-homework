#include <iostream>
#include <string>

#include "json.hpp"
#include "Address.h"

using json = nlohmann::json;

Project::Address::Address(const json& serializedObject)
{
	this->town = serializedObject["town"];
	this->street = serializedObject["street"];
	this->buildingNumber = serializedObject["building_number"];
	this->flatNumber = serializedObject["flat_number"];
}

Project::Address::operator std::string() const
{
	return this->town + ", "
		+ this->street + ", "
		+ ((this->flatNumber == 0) ? 
			std::to_string(this->buildingNumber) : 
			std::to_string(this->buildingNumber) + "/" + std::to_string(this->flatNumber));
}

std::ostream& Project::Address::operator<<(std::ostream& out) const
{
	return out << std::string(*this);
}

json Project::Address::serialize() const
{
	return {
		{"town", this->town},
		{"street", this->street},
		{"building_number", this->buildingNumber},
		{"flat_number", this->flatNumber},
	};
}
