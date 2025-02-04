#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <chrono>

#include "Price.h"
#include "ProductionYear.h"
#include "Car.h"
#include "CarDealership.h"
#include "UserMenu.h"

int main()
{
	std::shared_ptr<UserMenu> userMenu = UserMenu::getInstance(std::make_unique<CarDealership>());
	userMenu->showMenu();
	
	return 0;
}