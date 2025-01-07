#include <iostream>

#include "Pet.h"

Project::Pet::Pet(const json& serializedObject)
	: name(serializedObject["name"]), 
	birthDate(serializedObject["birth_date"])
{
	this->petType = PetType(serializedObject["pet_type"]);
	this->weight = serializedObject["weight"];
}

void Project::Pet::setName(const std::string& name)
{
	if (name.empty())
		throw gcnew System::ArgumentNullException("Name cannot be empty");

	this->name = name;
}

void Project::Pet::setBirthDate(const Date& birthDate)
{
	this->birthDate = birthDate;
}

void Project::Pet::setPetType(const PetType& petType)
{
	this->petType = petType;
}

void Project::Pet::setWeight(float weight)
{
	this->weight = weight;
}

json Project::Pet::serialize() const
{
	return {
		{"name", this->name},
		{"birth_date", this->birthDate.serialize()},
		{"pet_type", this->petType},
		{"weight", this->weight},
	};
}
