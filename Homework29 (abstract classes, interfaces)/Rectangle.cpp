#include <iostream>
#include <string>

#include "ISerializable.h"
#include "json.hpp"
#include "Shape.h"

#include "Rectangle.h"

Rectangle::Rectangle(const std::array<int, 2>& coordinatesOfLeftAngle, length widthLength, length lengthLength)
{
	if (widthLength == 0 || lengthLength == 0)
		throw std::invalid_argument("Length of side cannot be null");

	this->coordinatesOfLeftAngle = coordinatesOfLeftAngle;
	this->widthLength = widthLength;
	this->lengthLength = lengthLength;

	this->shapeType = ShapeType::RECTANGLE;
}

void Rectangle::show() const
{
	for (int i = 0; i < this->coordinatesOfLeftAngle[1]; i++)
		std::cout << '\n';

	for (int i = 0; i < this->widthLength; i++)
	{
		for (int k = 0; k < this->coordinatesOfLeftAngle[0]; k++)
			std::cout << "  ";

		for (int j = 0; j < this->lengthLength; j++)
			std::cout << "*" << ' ';

		std::cout << '\n';
	}
}

json Rectangle::serialize() const
{
	json result = Shape::serialize();

	result["width_length"] = int(this->widthLength);
	result["length_length"] = int(this->lengthLength);

	return result;
}

void Rectangle::deserialize(const json& serializedObject)
{
	Shape::deserialize(serializedObject);

	this->widthLength = serializedObject.at("width_length").get<length>();
	this->lengthLength = serializedObject.at("length_length").get<length>();
}
