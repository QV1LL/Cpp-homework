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

	public:

		explicit Pet(const json& serializedObject);

		Name getName() const { return this->name; }
		Date getBirthDate() const { return this->birthDate; }
		PetType getPetType() const { return this->petType; }
		float getWeight() const { return this->weight; }

		virtual json serialize() const;
	};
}

