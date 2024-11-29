#include "Initials.h"
#include "PhoneNumber.h"

#pragma once

class Contact
{
public:

	Initials initials;
	PhoneNumber* homeNumber;
	PhoneNumber* workNumber;
	PhoneNumber* phoneNumber;
	std::string additionalInfo = " ";

	Contact(Initials initials,
		const std::string& homeNumber,
		const std::string& workNumber,
		const std::string& phoneNumber,
		const std::string& additionalInfo = " ") 
		
		: initials(initials),
		additionalInfo(additionalInfo)
	{
		this->homeNumber = new PhoneNumber(homeNumber);
		this->workNumber = new PhoneNumber(workNumber);
		this->phoneNumber = new PhoneNumber(phoneNumber);
	}

	auto copy() const -> Contact*;

	~Contact();
};

