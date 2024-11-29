#include <iostream>
#include <vector>

#include "PhoneNumber.h"
#include "Initials.h"
#include "Contact.h"
#include "ClientContactList.h"

int main() {
	ClientContactList* clientContactsList = ClientContactList::getInstance();

	Contact* contact = new Contact({ "Oleksandr", "Oleksandrovich", "Vereschchagin" },
		"+380500000000",
		"+380500000000",
		"+380500000000",
		"Very professional Python hater and PHP Laravel developer");

	clientContactsList->addContact(contact->copy())
		->printContacts()
		->smsContact(0, "Laravel is awful")
		->smsContact(0, "Ohh.. Thats was joke, don`t mind.")
		->deleteContact(0);

	return 0;
}