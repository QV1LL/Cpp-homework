#include <iostream>

#include "Child.h"

Project::Child::Child(const json& serializedObject)
    : FamilyMember(serializedObject)
{
    this->educationPlace = serializedObject["education_place"];
}

void Project::Child::setEducationPlace(const std::string& educationPlace)
{
    if (educationPlace.empty())
        throw gcnew System::ArgumentNullException("Education place cannot be null string");

    this->educationPlace = educationPlace;
}

json Project::Child::serialize() const
{
    json result = FamilyMember::serialize();
    result["education_place"] = this->educationPlace;

    return result;
}
