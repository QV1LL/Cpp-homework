#include <iostream>
#include <string>

#include "Fraction.h"

auto getTheLeastCommonMultiple(int number1, int number2) -> int;

std::string Fraction::toString() const {
    std::string stringNumerator = std::to_string(this->_numerator);
    std::string stringDenominator = std::to_string(this->_denominator);

    size_t separatorLineLenght = (stringNumerator.size() > stringDenominator.size()) ? 
        stringNumerator.size() : stringDenominator.size();

    std::string separatorLine;

    for (int i = 0; i < separatorLineLenght; i++) separatorLine.append("-");

    return stringNumerator + '\n' + separatorLine + '\n' + stringDenominator;
}

Fraction Fraction::operator+(const Fraction& fraction) const {
    int denominator = getTheLeastCommonMultiple(this->getDenominator(), fraction.getDenominator());
    
    return Fraction(
        (denominator / this->getDenominator()) * this->_numerator + (denominator / fraction.getDenominator()) * fraction._numerator,
        denominator
    );
}

Fraction Fraction::operator-(const Fraction& fraction) const {
    int denominator = getTheLeastCommonMultiple(this->getDenominator(), fraction.getDenominator());

    return Fraction(
        (denominator / this->getDenominator()) * this->_numerator - (denominator / fraction.getDenominator()) * fraction._numerator,
        denominator
    );
}

Fraction Fraction::operator*(const Fraction& fraction) const {
    return Fraction(
        this->_numerator * fraction._numerator,
        this->_denominator * fraction._denominator
    );
}

Fraction Fraction::operator/(const Fraction& fraction) const {
    return Fraction(
        this->_numerator * fraction._denominator,
        this->_denominator * fraction._numerator
    );
}