#pragma once

#include "Pet.h"
#include "FamilyMember.h"
#include "Parent.h"
#include "Child.h"

namespace Project {
	
	class Family
	{
	private:

		Parent father;
		Parent mother;

		std::vector<Child> childs;
		std::vector<Pet> pets;

	public:


	};
}

