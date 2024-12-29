#pragma once

#include "Name.h"
#include "Date.h"

namespace Project {
	
	enum class PetType {
		DOG,
		CAT,
		PARROT,
		HAMSTER,
	};

	class Pet
	{
	private:

		Name name;
		Date birthDate;
		PetType petType;

		float weight;
	};
}

