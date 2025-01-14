#pragma once

using json = nlohmann::json;
using length = size_t; // size_t --> awful naming

class Elipse : public Shape
{
private:

	length widthLength;
	length lengthLength;

public:

	Elipse(const std::array<int, 2>& coordinatesOfLeftAngle,
		length widthLength,
		length lengthLength);

	virtual void show() const override;
	virtual json serialize() const override;
	virtual void deserialize(const json& serializedObject) override;
};

