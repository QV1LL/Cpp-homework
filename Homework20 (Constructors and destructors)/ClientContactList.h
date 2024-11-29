#include "Contact.h"

#pragma once

class ClientContactList
{
private:

	static ClientContactList* instance;

	std::vector<Contact> contacts;

	ClientContactList() = default;

public:

	static auto getInstance() -> ClientContactList*;

	auto addContact(Contact* contact) -> ClientContactList*;
	auto deleteContact(int id) -> ClientContactList*;
	auto smsContact(int id, const std::string& text) -> ClientContactList*;
	auto printContacts() -> ClientContactList*;
};

