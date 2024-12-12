#pragma once

enum class AirplaneType {
	PASSANGER,
	CARGO,
	MILLITARY,
};

class Airplane
{
private:

	AirplaneType airplaneType;
	int passangersCount;

public:

	Airplane(AirplaneType airplaneType, int passangersCount);

	bool operator== (const Airplane& other) const { return this->airplaneType == other.airplaneType; }

	bool operator> (const Airplane& other) const { return this->passangersCount > other.passangersCount; }

	bool operator< (const Airplane& other) const { return this->passangersCount < other.passangersCount; }

	void operator++(int);

	void operator--(int);
};

