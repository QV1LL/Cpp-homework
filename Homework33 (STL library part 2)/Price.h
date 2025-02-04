#pragma once

class Price
{
private:

	int fullPart;
	int hundredthPart;

public:

	Price(float price);

	explicit Price(int fullPart, int hundredthPart);

	operator float() const { return this->fullPart + float(hundredthPart) / 100; }
};

