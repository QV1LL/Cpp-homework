#include <iostream>
#include <string>

#include "json.hpp"
#include "Address.h"

using json = nlohmann::json;

Project::Address::Address(const json& serializedObject)
{
	this->town = serializedObject.at("town").get<std::string>();
	this->street = serializedObject.at("street").get<uint16_t>();
	this->buildingNumber = serializedObject.at("building_number").get<uint16_t>();
	this->flatNumber = serializedObject.at("flat_number").get<uint16_t>();
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
		{"building_number", std::to_string(this->buildingNumber)},
		{"flat_number", std::to_string(this->flatNumber)},
	};
}
