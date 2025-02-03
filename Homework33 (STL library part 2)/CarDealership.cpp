#include <iostream>
#include <vector>

#include "Car.h"
#include "CarDealership.h"

Car& CarDealership::getCarById(int carId)
{
    if (carId < 0 || this->cars.size() <= carId)
        std::out_of_range("Index was out of bounds");

    return this->cars[carId];
}

void CarDealership::deleteCarById(int carId)
{
    cars.erase(std::remove_if(cars.begin(),
        cars.end(),
        [carId](const Car& car)
        {
            return car.getId() == carId;
        }),
        cars.end());
}
