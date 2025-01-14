#pragma once

using json = nlohmann::json;

enum class ShapeType
{
	SQUARE,
	RECTANGLE,
	CIRCLE,
	ELIPSE,
};

class Shape : public ISerializable
{
protected:

	ShapeType shapeType;
	std::array<int, 2> coordinatesOfLeftAngle;

public:

	virtual void show() const = 0;

	virtual json serialize() const;

	virtual void deserialize(const json& serializedObject);
};

