#pragma once

using json = nlohmann::json;
using length = size_t; // size_t --> awful naming

class Square : public Shape
{
private:

	length sideLength;

public:

	Square(const std::array<int, 2>& coordinatesOfLeftAngle,
		length sideLength);

	virtual void show() const override;
	virtual json serialize() const override;
	virtual void deserialize(const json& serializedObject) override;

};

