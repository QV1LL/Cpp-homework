#include <iostream>

#include "Parent.h"

Project::Parent::Parent(const json& serializedObject)
	: FamilyMember(serializedObject)
{
	this->job = serializedObject["job"];
}

void Project::Parent::setJob(const std::string& job)
{
	if (job.empty())
		throw gcnew System::ArgumentNullException("Job cannot be null string");

	this->job = job;
}

void Project::Parent::setBirthDate(const Date& birthDate)
{
	if (Project::getCurrentYear() - birthDate.getYear() < 18)
		throw gcnew System::ArgumentException("Parent cannot be minor");

	FamilyMember::setBirthDate(birthDate);
}

json Project::Parent::serialize() const
{
	json result = FamilyMember::serialize();
	result["job"] = this->job;

	return result;
}
