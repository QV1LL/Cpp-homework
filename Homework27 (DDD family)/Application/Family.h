#pragma once

#include "Pet.h"
#include "FamilyMember.h"
#include "Parent.h"
#include "Child.h"

namespace Project {

	class Family
	{
	private:

		int id;
		static int ID_COUNTER;
		static int MAX_CHILDREN_COUNT;

		std::string familyName;

		Parent father;
		Parent mother;

		std::vector<Child> childs;
		std::vector<Pet> pets;

	public:

		Family(Parent father, 
			Parent mother, 
			const std::string& familyName);
		explicit Family(const json& serializedObject);
		
		void setName(const std::string& name);
		std::string getName() const { return this->familyName; }

		void setFather(const Parent& father) { this->father = father; }
		Parent getFather() const { return this->father; }

		void setMother(const Parent& mother) { this->mother = mother; }
		Parent getMother() const { return this->mother; }

		void addChild(const Child& child);
		void setChild(const Child& child, int id);
		void deleteChild(int id);
		Child getChild(size_t id) const { return this->childs[id]; }

		void addPet(const Pet& pet) { this->pets.push_back(pet); }
		void setPet(const Pet& pet, int id) { this->pets[id] = pet; }
		void deletePet(int id);
		Pet getPet(size_t id) const { return this->pets[id]; }

		json serialize() const;
	};
}

