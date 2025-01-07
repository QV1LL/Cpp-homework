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
			Gender gender,
			const std::string& job = "unemployed",
			const std::string& nationality = "undefined")
			: FamilyMember(name, birthDate, phoneNumber, gender, nationality)
		{
			if (!job.empty())
				this->job = job;
		}

		explicit Parent(const json& serializedObject);

		void setJob(const std::string& job);
		std::string getJob() const { return this->job; }

		void setBirthDate(const Date& birthDate) override;

		json serialize() const override;
	};
}