#include "json.hpp"
#include "ISerializable.h"

#include "Shape.h"

json Shape::serialize() const
{
	json serializedObject{
		{"left_angle_x", this->coordinatesOfLeftAngle[0]},
		{"left_angle_y", this->coordinatesOfLeftAngle[1]},
		{"shape_type", this->shapeType},
	};

	return serializedObject;
}

void Shape::deserialize(const json& serializedObject)
{
	this->coordinatesOfLeftAngle[0] = serializedObject.at("left_angle_x").get<float>();
	this->coordinatesOfLeftAngle[1] = serializedObject.at("left_angle_y").get<float>();
	this->shapeType = ShapeType(serializedObject.at("shape_type").get<int>());
}
