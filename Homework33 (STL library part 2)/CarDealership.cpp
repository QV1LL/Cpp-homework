#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>

#include "Car.h"
#include "CarDealership.h"

int CarDealership::currentId = 0;

Car& CarDealership::getCarById(int carId)
{
    if (carId < 0 || this->cars.size() <= carId)
        std::out_of_range("Index was out of bounds");

    return this->cars[carId];
}

void CarDealership::deleteCarById(int carId)
{
    this->cars.erase(std::remove_if(this->cars.begin(),
        this->cars.end(),
        [carId](const Car& car)
        {
            return car.getId() == carId;
        }),
        this->cars.end());
}

void CarDealership::displayCars() const
{
    for (const Car& car : this->cars)
    {
        std::cout << "\n\nBrand: " << car.getBrand() << '\n'
            << "Model: " << car.getModel() << '\n'
            << "Production year: " << car.getYear().getYear() << '\n'
            << "Engine volume: " << car.getEngineVolume() << '\n'
            << "Engine type: " << int(car.getEngineType()) << '\n'
            << "Price: " << car.getPrice() << '\n';
    }
}

void CarDealership::sortCarsByProductYear()
{
    std::sort(this->cars.begin(), this->cars.end(),
        [](const Car& car1, const Car& car2) {
            return car1.getYear().getYear() < car2.getYear().getYear();
        });
}

void CarDealership::sortCarsByPrice()
{
    std::sort(this->cars.begin(), this->cars.end(),
        [](const Car& car1, const Car& car2) {
            return car1.getPrice() < car2.getPrice();
        });
}

