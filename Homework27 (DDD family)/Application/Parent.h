#pragma once

#include "FamilyMember.h"

namespace Project {
	
	class Parent : public FamilyMember
	{
	private:

		std::string job;

	public:

		Parent(const Name& name,
			const Date& birthDate,
			const PhoneNumber phoneNumber,
			Sex sex,
			const std::string& job = "unemployed",
			const std::string& nationality = "undefined")
			: FamilyMember(name, birthDate, phoneNumber, sex, nationality)
		{
			if (!job.empty())
				this->job = job;
		}

		std::string getJob() const { return this->job; }
	};
}