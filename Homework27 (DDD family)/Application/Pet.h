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

		std::string name;
		Date birthDate;
		PetType petType;

		float weight;

	public:
		Pet(const std::string& name,
			const Date& birthDate,
			const PetType& petType,
			float weight)
			: birthDate(birthDate)
		{
			this->setName(name);
			this->setPetType(petType);
			this->setWeight(weight);
		}

		explicit Pet(const json& serializedObject);

		void setName(const std::string& name);
		std::string getName() const { return this->name; }

		void setBirthDate(const Date& birthDate);
		Date getBirthDate() const { return this->birthDate; }

		void setPetType(const PetType& petType);
		PetType getPetType() const { return this->petType; }

		void setWeight(float weight);
		float getWeight() const { return this->weight; }

		virtual json serialize() const;
	};
}

