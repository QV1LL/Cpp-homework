#pragma once
class Flat
{
private:

	double square;
	int price;

public:

	Flat(double square, int price);

	Flat& operator= (const Flat& other);

	bool operator> (const Flat& other) const { return this->price > other.price; }

	bool operator< (const Flat& other) const { return this->price < other.price; }

	bool operator== (const Flat& other) const { return this->square == other.square; }
};

