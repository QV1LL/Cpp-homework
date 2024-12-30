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

		Parent father;
		Parent mother;

		std::vector<Child> childs;
		std::vector<Pet> pets;

	public:

		Family(Parent father, Parent mother);

		void addChild();
		void addPet();

		void editChild();
		void editPet();

	};
}

