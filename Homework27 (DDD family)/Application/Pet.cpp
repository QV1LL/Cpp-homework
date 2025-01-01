#include <iostream>

#include "Pet.h"

Project::Pet::Pet(const json& serializedObject)
	: name(serializedObject["name"]), 
	birthDate(serializedObject["birth_date"])
{
	this->petType = PetType(serializedObject["pet_type"]);
	this->weight = serializedObject["weight"];
}

json Project::Pet::serialize() const
{
	return {
		{"name", this->name.serialize()},
		{"birth_date", this->birthDate.serialize()},
		{"pet_type", this->petType},
		{"weight", this->weight},
	};
}
