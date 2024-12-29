#include <iostream>
#include <string>

#include "Address.h"

Project::Address::operator std::string() const
{
	return this->town + ", "
		+ this->street + ", "
		+ ((this->flatNumber == 0) ? 
			std::to_string(this->buildingNumber) : 
			std::to_string(this->buildingNumber) + "/" + std::to_string(this->flatNumber));
}

std::ostream& Project::Address::operator<<(std::ostream& out) const
{
	return out << std::string(*this);
}
