#include <iostream>
#include <vector>

#include "json.hpp"
#include "Family.h"
#include "Parent.h"

int Project::Family::ID_COUNTER = 0;
int Project::Family::MAX_CHILDREN_COUNT = 4;

Project::Family::Family(Parent father, 
	Parent mother, 
	const std::string& familyName)
	: father(father), mother(mother)
{
	this->setName(familyName);
	this->id = Family::ID_COUNTER++;
}

Project::Family::Family(const json& serializedObject)
	: father(serializedObject["father"]),
	mother(serializedObject["mother"]),
	familyName(serializedObject["family_name"])

{
	if (serializedObject.contains("children"))
		for (auto [key, value] : serializedObject["children"].items())
			this->childs.push_back(Child(value));

	if (serializedObject.contains("pets"))
		for (auto [key, value] : serializedObject["pets"].items())
			this->pets.push_back(Pet(value));

	this->id = Family::ID_COUNTER++;
}

void Project::Family::setName(const std::string& name)
{
	if (name.empty())
		throw gcnew System::ArgumentNullException("Family name cannot be empty");

	this->familyName = name;
}

void Project::Family::addChild(const Child& child)
{
	if (child.getBirthDate().getYear() - 
		std::max(this->father.getBirthDate().getYear(),
		this->mother.getBirthDate().getYear()) - 18 < 0)
		throw gcnew System::ArgumentException("Child age is incorrect!");

	this->childs.push_back(child);
}

void Project::Family::setChild(const Child& child, int id)
{
	if (child.getBirthDate().getYear() -
		std::max(this->father.getBirthDate().getYear(),
			this->mother.getBirthDate().getYear()) - 18 < 0)
		throw gcnew System::ArgumentException("Child age is incorrect!");

	this->childs[id] = child;
}

void Project::Family::deleteChild(int id)
{
	if (id < 0 || id >= this->childs.size())
		throw gcnew System::IndexOutOfRangeException("Index was out of range");

	this->childs.erase(this->childs.begin() + id);
}

void Project::Family::deletePet(int id)
{
	if (id < 0 || id >= this->pets.size())
		throw gcnew System::IndexOutOfRangeException("Index was out of range");

	this->pets.erase(this->pets.begin() + id);
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
