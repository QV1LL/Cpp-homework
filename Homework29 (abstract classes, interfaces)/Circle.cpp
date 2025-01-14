#include <iostream>
#include <string>
#include <cmath>

#include "ISerializable.h"
#include "json.hpp"
#include "Shape.h"

#include "Circle.h"

Circle::Circle(const std::array<int, 2>& coordinatesOfLeftAngle, length radius)
{
	if (radius == 0)
		throw std::invalid_argument("Radius cannot be null");

	this->coordinatesOfLeftAngle = coordinatesOfLeftAngle;
	this->radius = radius;

	this->shapeType = ShapeType::CIRCLE;
}

void Circle::show() const
{ 
	for (int i = 0; i < this->coordinatesOfLeftAngle[1]; i++)
		std::cout << '\n';

	for (int y = -int(this->radius); y <= int(this->radius); y++) 
	{
		for (int i = 0; i < this->coordinatesOfLeftAngle[0]; i++)
			std::cout << "   ";

		for (int x = -int(this->radius); x <= int(this->radius); x++) 
		{
			if (std::sqrt(x * x + y * y) <= int(this->radius))
				std::cout << " * ";
			else 
				std::cout << "   ";
		}
		std::cout << "\n";
	}
}

json Circle::serialize() const
{
	json result = Shape::serialize();

	result["radius"] = this->radius;

	return result;
}

void Circle::deserialize(const json& serializedObject)
{
	Shape::deserialize(serializedObject);

	this->radius = serializedObject.at("radius").get<length>();
}