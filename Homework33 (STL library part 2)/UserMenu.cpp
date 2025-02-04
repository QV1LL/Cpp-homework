#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>

#include "Car.h"
#include "CarDealership.h"
#include "UserMenu.h"

std::shared_ptr<UserMenu> UserMenu::instance = nullptr;

UserMenu::UserMenu(std::unique_ptr<CarDealership> dealership)
	: dealership(std::move(dealership))
{

}

std::shared_ptr<UserMenu> UserMenu::getInstance(std::unique_ptr<CarDealership> dealership)
{
	if (UserMenu::instance == nullptr)
        UserMenu::instance = std::unique_ptr<UserMenu>{ new UserMenu{ std::move(dealership) } };

	return UserMenu::instance;
}

void UserMenu::showMenu()
{
    int choice;
    do {
        std::cout << "\nCar Dealership Menu:\n";
        std::cout << "1. Add Car\n2. Delete Car\n3. Display Cars\n4. Sort Cars by condition\n5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addCarToDealership();
            break;
        case 2:
            deleteCarFromDealership();
            break;
        case 3:
            this->dealership->displayCars();
            break;
        case 4:
            sortCarsByCondition();
            break;
        case 5:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);
}

void UserMenu::sortCarsByCondition()
{
    int sortChoice;
    std::cout << "Choose sorting condition:\n";
    std::cout << "1. Sort by Year\n2. Sort by Price\n";
    std::cout << "Enter your choice: ";
    std::cin >> sortChoice;

    switch (sortChoice) {
    case 1:
        this->dealership->sortCarsByProductYear();
        break;
    case 2:
        this->dealership->sortCarsByPrice();
        break;
    default:
        std::cout << "Invalid choice. Sorting not applied.\n";
    }
}

void UserMenu::addCarToDealership()
{
    try
    {
        std::string brand;
        std::string model;
        size_t year;
        float engineVolume;
        int engineType;
        float price;

        std::cout << "Enter brand: ";
        std::cin >> brand;
        std::cout << "Enter model: ";
        std::cin >> model;
        std::cout << "Enter year: ";
        std::cin >> year;
        std::cout << "Enter engine volume: ";
        std::cin >> engineVolume;
        std::cout << "Enter engine type (1 - 16) : ";
        std::cin >> engineType;
        std::cout << "Enter price amount: ";
        std::cin >> price;

        this->dealership->addCar(Car{ brand, model, ProductionYear{ year }, engineVolume, static_cast<EngineType>(engineType), Price{price} });
    }
    catch (std::exception e)
    {
        std::cout << "Invalid input, cannot add car";
    }
}

void UserMenu::deleteCarFromDealership()
{
    int carId;
    std::cout << "Enter car ID to delete: ";
    std::cin >> carId;
    this->dealership->deleteCarById(carId);
}
