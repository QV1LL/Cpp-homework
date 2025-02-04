#pragma once

#include "Price.h"
#include "ProductionYear.h"

enum class EngineType
{
	INLINE_4,
	INLINE_4_TURBO,
	INLINE_6,
	INLINE_6_TURBO,
	INLINE_6_TWIN_TURBO,
	V6,
	V6_TURBO,
	V6_TWIN_TURBO,
	V8,
	V8_TWIN_TURBO,
	V8_COMPRESSOR,
	V8_BARREL,
	V10,
	V10_TWIN_TURBO,
	V12,
	V12_TWIN_TURBO,
};

class Car
{
private:
	static int currentId;
	int id;

	std::string brand;
	std::string model;

	ProductionYear year;
	float engineVolume;
	EngineType engineType;
	Price price;

public:

	Car(const std::string& brand, 
		const std::string& model, 
		ProductionYear year,
		float engineVolume, 
		EngineType engineType, 
		Price price);

	int getId() const { return id; }
	std::string getBrand() const { return brand; }
	std::string getModel() const { return model; }
	ProductionYear getYear() const { return year; }
	float getEngineVolume() const { return engineVolume; }
	EngineType getEngineType() const { return engineType; }
	Price getPrice() const { return price; }

	void setBrand(const std::string& brand);
	void setModel(const std::string& model);
	void setYear(ProductionYear year);
	void setEngineVolume(float engineVolume);
	void setEngineType(EngineType engineType) { this->engineType = engineType; }
	void setPrice(Price price) { this->price = price; }
};

