#include "complexNumber.h"
#include <iostream>

auto printComplexNumber(ComplexNumber complexNumber) -> void {
	if (complexNumber.realPart && complexNumber.imaginePartCounter)
		std::printf("%g %c %gi", complexNumber.realPart, 
			(complexNumber.imaginePartCounter < 0) ? '-' : '+',

			[] (double number) {
				return (number > 0) ? number : -number;
			} (complexNumber.imaginePartCounter));

	else if (complexNumber.realPart)
		std::printf("%g", complexNumber.realPart);
	else if (complexNumber.imaginePartCounter) {
		std::printf("%gi", complexNumber.imaginePartCounter);
	}
}

auto getSumOfComplexNumbers(ComplexNumber complexNumber1, ComplexNumber complexNumber2) -> ComplexNumber {
	double realPart = complexNumber1.realPart + complexNumber2.realPart;
	double imaginePartCounter = complexNumber1.imaginePartCounter + complexNumber2.imaginePartCounter;

	return ComplexNumber{ realPart, imaginePartCounter };
}

auto getSubstractOfComplexNumbers(ComplexNumber complexNumber1, ComplexNumber complexNumber2) -> ComplexNumber {
	double realPart = complexNumber1.realPart - complexNumber2.realPart;
	double imaginePartCounter = complexNumber1.imaginePartCounter - complexNumber2.imaginePartCounter;

	return ComplexNumber{ realPart, imaginePartCounter };
}

auto getMultiplyOfComplexNumbers(ComplexNumber complexNumber1, ComplexNumber complexNumber2) -> ComplexNumber {
	double realPart = (complexNumber1.realPart * complexNumber2.realPart) - (complexNumber1.imaginePartCounter * complexNumber2.imaginePartCounter);
	double imaginePartCounter = (complexNumber1.realPart * complexNumber2.imaginePartCounter) + (complexNumber1.imaginePartCounter * complexNumber2.realPart);

	return ComplexNumber{ realPart, imaginePartCounter };
}

auto getDivisionOfComplexNumbers(ComplexNumber complexNumber1, ComplexNumber complexNumber2) -> ComplexNumber {
	double realPart1 = complexNumber1.realPart;
	double realPart2 = complexNumber2.realPart;

	double imaginePart1 = complexNumber1.imaginePartCounter;
	double imaginePart2 = complexNumber2.imaginePartCounter;

	double realPart = ((realPart1 * realPart2) + (imaginePart1 * imaginePart2)) /
		((realPart2 * realPart2) + (imaginePart2 * imaginePart2));

	double imaginePartCounter = ((imaginePart1 * realPart2) - (realPart1 * imaginePart2)) /
		((realPart2 * realPart2) + (imaginePart2 * imaginePart2));

	return ComplexNumber{ realPart, imaginePartCounter };
}