#pragma once

class CarDealership
{
private:

	static int currentId;
	int id;

	std::vector<Car> cars;

public:

    CarDealership() 
        : id(++currentId) 
    {

    }

    void addCar(const Car& car) { cars.push_back(car); }
    Car& getCarById(int carId);
    void deleteCarById(int carId);
    void displayCars() const;

    void sortCarsByProductYear();
    void sortCarsByPrice();
};

