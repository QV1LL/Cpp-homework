#include <iostream>

#include "Contact.h"

Contact::~Contact() {
	delete this->homeNumber;
	delete this->phoneNumber;
	delete this->workNumber;
}

auto Contact::copy() const -> Contact* {
	return new Contact(this->initials,
		this->homeNumber->getNumber(),
		this->workNumber->getNumber(),
		this->phoneNumber->getNumber(),
		this->additionalInfo);
}