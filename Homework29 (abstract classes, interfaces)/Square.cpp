#include <iostream>
#include <string>

#include "ISerializable.h"
#include "json.hpp"
#include "Shape.h"

#include "Square.h"

Square::Square(const std::array<int, 2>& coordinatesOfLeftAngle, length sideLength)
{
	if (sideLength == 0)
		throw std::invalid_argument("Length of side cannot be null");

	this->coordinatesOfLeftAngle = coordinatesOfLeftAngle;
	this->sideLength = sideLength;

	this->shapeType = ShapeType::SQUARE;
}

void Square::show() const
{
	for (int i = 0; i < this->coordinatesOfLeftAngle[1]; i++)
		std::cout << '\n';

	for (int i = 0; i < this->sideLength; i++)
	{
		for (int k = 0; k < this->coordinatesOfLeftAngle[0]; k++)
			std::cout << "  ";

		for (int j = 0; j < this->sideLength; j++)
			std::cout << "*" << ' ';

		std::cout << '\n';
	}
}

json Square::serialize() const
{

	json result = Shape::serialize();
	
	result["side_length"] = this->sideLength;

	return result;
}

void Square::deserialize(const json& serializedObject)
{
	Shape::deserialize(serializedObject);

	this->sideLength = serializedObject.at("side_length").get<length>();
}
