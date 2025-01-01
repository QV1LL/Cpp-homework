#include <iostream>

#include "Parent.h"

Project::Parent::Parent(const json& serializedObject)
	: FamilyMember(serializedObject)
{
	this->job = serializedObject["job"];
}

json Project::Parent::serialize() const
{
	json result = FamilyMember::serialize();
	result["job"] = this->job;

	return result;
}
