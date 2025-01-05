#include <iostream>
#include <vector>

#include "json.hpp"
#include "Family.h"
#include "Parent.h"

int Project::Family::ID_COUNTER = 0;
int Project::Family::MAX_CHILDREN_COUNT = 5;

Project::Family::Family(Parent father, 
	Parent mother, 
	const std::string& familyName)
	: father(father), mother(mother)
{
	if (familyName.empty())
		throw gcnew System::ArgumentNullException("Family name cannot be empty");

	this->id = Family::ID_COUNTER++;
}

Project::Family::Family(const json& serializedObject)
	: father(serializedObject["father"]),
	mother(serializedObject["mother"]),
	familyName(serializedObject["family_name"])

{
	int i = 0;
	while (true) {
		if (serializedObject["children"]["child" + std::to_string(i)] == "")
			break;

		this->childs.push_back(Child(serializedObject["children"]["child" + std::to_string(i++)]));
	}

	i = 0;
	while (true) {
		if (serializedObject["pets"]["pet" + std::to_string(i)] == "")
			break;

		this->pets.push_back(Pet(serializedObject["pets"]["pet" + std::to_string(i++)]));
	}

	this->id = Family::ID_COUNTER++;
}

void Project::Family::addChild(const Child& child)
{
	if (std::min(this->father.getBirthDate().getYear(), 
		this->mother.getBirthDate().getYear()) - child.getBirthDate().getYear() - 18 < 0)
		throw gcnew System::ArgumentException("Child age is incorrect!");

	this->childs.push_back(child);
}

json Project::Family::serialize() const
{
	json serializedObject = {
		{"father", this->father.serialize()},
		{"mother", this->mother.serialize()},
		{"family_name", this->familyName},
	};

	int i = 0;
	for (Child child : this->childs)
		serializedObject["children"]["child" + std::to_string(i++)]
			= child.serialize();

	i = 0;
	for (Pet pet : this->pets)
		serializedObject["pets"]["pet" + std::to_string(i++)]
		= pet.serialize();

	return serializedObject;
}
