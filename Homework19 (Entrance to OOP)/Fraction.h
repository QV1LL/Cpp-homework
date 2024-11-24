#pragma once

class Fraction {
private:

	int _numerator;
	int _denominator;

public:

	Fraction(int numerator, int denominator) {
		this->setNumerator(numerator);
		this->setDenominator(denominator);
	}

	auto setNumerator(int numerator) -> void {
		this->_numerator = numerator;
	}
	auto getNumerator() const -> int { return this->_numerator; }


	auto setDenominator(int denominator) -> void {
		if (denominator == 0)
			throw std::exception("Divided by zero!");

		this->_denominator = denominator;
	}
	auto getDenominator() const -> int { return this->_denominator; }

	auto toString() const -> std::string;

	auto toDouble() const -> double {
		return this->getNumerator() / this->getDenominator();
	}

	auto operator+(const Fraction& fraction) const -> Fraction;
	auto operator-(const Fraction& fraction) const -> Fraction;
	auto operator/(const Fraction& fraction) const -> Fraction;
	auto operator*(const Fraction& fraction) const -> Fraction;
};