#include <iostream>

#include "Car.h"
#include "CarDealership.h"
#include "UserMenu.h"

UserMenu::UserMenu(std::unique_ptr<CarDealership> dealership)
	: dealership(std::move(dealership))
{

}

std::shared_ptr<UserMenu> UserMenu::getInstance()
{
	if (UserMenu::instance == nullptr)
		UserMenu::instance = std::make_shared<UserMenu>();

	return UserMenu::instance;
}
