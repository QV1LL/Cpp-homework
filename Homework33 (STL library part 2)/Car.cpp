#include <iostream>

#include "Price.h"
#include "ProductionYear.h"
#include "Car.h"

int Car::currentId = 0;

Car::Car(const std::string& brand,
	const std::string& model,
	ProductionYear year, 
	float engineVolume,
	EngineType engineType,
	Price price)
	: year(year),
	price(price)
{
	this->setBrand(brand);
	this->setModel(model);
	this->setEngineVolume(engineVolume);
	this->setEngineType(engineType);
}

void Car::setBrand(const std::string& brand)
{
	if (brand.empty())
		std::invalid_argument("Brand cannot be empty string");

	this->brand = brand;
}

void Car::setModel(const std::string& model)
{
	if (model.empty())
		std::invalid_argument("Model cannot be empty string");

	this->model = model;
}

void Car::setYear(ProductionYear year)
{
	this->year = year;
}

void Car::setEngineVolume(float engineVolume)
{
	if (engineVolume <= 0)
		std::invalid_argument("Engine volume must be positive value");

	this->engineVolume = engineVolume;
}