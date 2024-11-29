#include <iostream>
#include <vector>

#include "ClientContactList.h"

ClientContactList* ClientContactList::instance = nullptr;

auto ClientContactList::getInstance() -> ClientContactList* {
	if (instance == nullptr)
		instance = new ClientContactList();

	return ClientContactList::instance;
}

auto ClientContactList::addContact(Contact* contact) -> ClientContactList* {
	this->contacts.push_back(*contact);

	return this;
}

auto ClientContactList::deleteContact(int id) -> ClientContactList* {
	if (id < 0 && id >= this->contacts.size())
		throw std::out_of_range("Id was out of range!");

	this->contacts.erase(this->contacts.begin() + id);

	return this;
}

auto ClientContactList::smsContact(int id, const std::string& text) -> ClientContactList* {
	if (id < 0 && id >= this->contacts.size())
		throw std::out_of_range("Id was out of range!");

	std::cout << "You sms " << this->contacts[id].initials.name
		<< " and write:\n" << text << '\n';

	return this;
}

auto ClientContactList::printContacts() -> ClientContactList* {
	for (int i = 0; i < this->contacts.size(); i++) 
		std::cout << contacts[i].initials.name << " " << contacts[i].initials.surname
		<< ": " << contacts[i].phoneNumber->getNumber() << '\n';

	return this;
}