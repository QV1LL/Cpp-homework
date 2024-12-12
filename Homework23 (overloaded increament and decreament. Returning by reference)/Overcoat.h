#pragma once

enum class OvercoatType {
	JACKET,
	COAT,
	SMOKING,
};

class Overcoat
{
private:

	int price;
	OvercoatType overcoatType;

public:

	Overcoat(OvercoatType overcoatType, int price);

	bool operator== (const Overcoat& other) const { return this->overcoatType == other.overcoatType; }

	bool operator> (const Overcoat& other) const { return this->price > other.price; }

	bool operator< (const Overcoat& other) const { return this->price < other.price; }

	Overcoat& operator= (const Overcoat& other);
};

