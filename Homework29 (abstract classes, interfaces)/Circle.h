#pragma once

using json = nlohmann::json;
using length = size_t; // size_t --> awful naming

class Circle : public Shape
{
private:

	length radius;

public:

	Circle(const std::array<int, 2>& coordinatesOfLeftAngle,
		length radius);

	virtual void show() const override;
	virtual json serialize() const override;
	virtual void deserialize(const json& serializedObject) override;
};

