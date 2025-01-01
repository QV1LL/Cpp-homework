#include <iostream>

#include "Child.h"

Project::Child::Child(const json& serializedObject)
    : FamilyMember(serializedObject)
{
    this->educationPlace = serializedObject["education_place"];
}

json Project::Child::serialize() const
{
    json result = FamilyMember::serialize();
    result["education_place"] = this->educationPlace;

    return result;
}
