#pragma once

class Circle
{
private:

	double radius;

public:

	Circle(double radius);

	operator double() const { return this->radius; }

	bool operator== (const Circle& other) const { return this->radius == other.radius; }

	bool operator> (const Circle& other) const { return this->radius > other.radius; }

	bool operator< (const Circle& other) const { return this->radius < other.radius; }

	void operator+= (double radius) { this->radius += radius; }

	void operator-= (double radius) { this->radius -= radius; }
};

