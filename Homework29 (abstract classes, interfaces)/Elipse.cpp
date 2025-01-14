#include <iostream>
#include <string>
#include <cmath>

#include "ISerializable.h"
#include "json.hpp"
#include "Shape.h"

#include "Elipse.h"

Elipse::Elipse(const std::array<int, 2>& coordinatesOfLeftAngle, length widthLength, length lengthLength)
{
    if (widthLength == 0 || lengthLength == 0)
        throw std::invalid_argument("Length of side cannot be null");

    this->coordinatesOfLeftAngle = coordinatesOfLeftAngle;
    this->widthLength = widthLength;
    this->lengthLength = lengthLength;

    this->shapeType = ShapeType::ELIPSE;
}

void Elipse::show() const
{
    for (int i = 0; i < this->coordinatesOfLeftAngle[1]; i++)
        std::cout << '\n';

    for (int y = -int(this->widthLength); y <= int(this->widthLength); y++) 
    {
        for (int i = 0; i < this->coordinatesOfLeftAngle[0]; i++)
            std::cout << "   ";

        for (int x = -int(this->lengthLength); x <= int(this->lengthLength); x++) 
        {
            if ((static_cast<double>(x) * x) / (int(this->lengthLength) * int(this->lengthLength)) 
                + (static_cast<double>(y) * y) / (int(this->widthLength) * int(this->widthLength)) <= 1)
                std::cout << " * ";
            else
                std::cout << "   ";
        }
        std::cout << "\n";
    }

}

json Elipse::serialize() const
{
	json result = Shape::serialize();

    result["width_length"] = int(this->widthLength);
    result["length_length"] = int(this->lengthLength);

	return result;
}

void Elipse::deserialize(const json& serializedObject)
{
    Shape::deserialize(serializedObject);

    this->widthLength = serializedObject.at("width_length").get<length>();
    this->lengthLength = serializedObject.at("length_length").get<length>();
}