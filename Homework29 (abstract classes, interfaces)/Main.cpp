#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>

#include "Equation.h"
#include "LinearEquation.h"
#include "QuadraticEquation.h"

#include "json.hpp"
#include "ISerializable.h"
#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Elipse.h"

int main()
{
	std::vector<Shape*> shapes;

	for (const auto& entry : std::filesystem::directory_iterator("savings")) {
		std::ifstream fileStream("savings/" + entry.path().filename().string());

		if (!fileStream.is_open())
			continue;

		json serializedObject;
		fileStream >> serializedObject;

		if (serializedObject.at("shape_type").get<ShapeType>() == ShapeType::SQUARE)
		{
			Shape* shape = new Square({ 0, 0 }, 1);
			shape->deserialize(serializedObject);
			shapes.push_back(shape);
		}
		else if (serializedObject.at("shape_type").get<ShapeType>() == ShapeType::RECTANGLE)
		{
			Shape* shape = new Rectangle({ 0, 0 }, 1, 1);
			shape->deserialize(serializedObject);
			shapes.push_back(shape);
		}
		else if (serializedObject.at("shape_type").get<ShapeType>() == ShapeType::CIRCLE)
		{
			Shape* shape = new Circle({ 0, 0 }, 1);
			shape->deserialize(serializedObject);
			shapes.push_back(shape);
		}
		else if (serializedObject.at("shape_type").get<ShapeType>() == ShapeType::ELIPSE)
		{
			Shape* shape = new Elipse({ 0, 0 }, 1, 1);
			shape->deserialize(serializedObject);
			shapes.push_back(shape);
		}
	}

	int i = 1;
	for (Shape* shape : shapes)
	{
		shape->show();

		std::fstream file("savings/saving" + std::to_string(i++) + ".json", std::ios::out);
		file << shape->serialize();
	}

	Equation* equation = new LinearEquation(-23, -25);

	for (float& value : equation->getRoots())
		std::cout << value << "\n";

	return 0;
}