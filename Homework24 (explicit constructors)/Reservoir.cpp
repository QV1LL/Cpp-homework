#include <iostream>
#include <string>
#include <vector>

#include "Reservoir.h"

auto split(const std::string& str, char delimiter) -> std::vector<std::string> {
	std::vector<std::string> tokens;
	size_t start = 0;
	size_t end = str.find(delimiter);

	while (end != std::string::npos) {
		tokens.push_back(str.substr(start, end - start));
		start = end + 1;
		end = str.find(delimiter, start);
	}

	tokens.push_back(str.substr(start));
	return tokens;
}

Reservoir::Reservoir(const std::string& name, 
	ReservoirType reservoirType,
	double width,
	double length, 
	double depth)
{
	if (width <= 0 || length <= 0 || depth <= 0)
		throw std::invalid_argument("Value can be only positive!");

	this->reservoirType = reservoirType;
	this->name = name;
	this->width = width;
	this->length = length;
	this->depth = depth;
}

double Reservoir::getSquare() const
{
	return this->length * this->width;
}

double Reservoir::getVolume() const
{
	return this->getSquare() * this->depth;
}

bool Reservoir::isSquareBigger(const Reservoir& other) const
{
	return this->getSquare() > other.getSquare();
}

std::string Reservoir::toString() const
{
	return "Name: " + this->name + "\n"
		+ "Type: " + std::to_string(int(this->reservoirType)) + "\n"
		+ "Width: " + std::to_string(this->width) + "\n"
		+ "Length: " + std::to_string(this->length) + "\n"
		+ "Depth: " + std::to_string(this->depth) + "\n";
}

bool Reservoir::operator==(const Reservoir& other) const
{
	return this->reservoirType == other.reservoirType;
}

Reservoir& Reservoir::operator=(const Reservoir& other)
{
	if (this == &other) return *this;

	this->name = other.name;
	this->reservoirType = other.reservoirType;
	this->length = other.length;
	this->width = other.width;
	this->depth = other.depth;

	return *this;
}

std::string Reservoir::serialize() const
{
	return this->name + "|"
		+ std::to_string(int(this->reservoirType)) + "|"
		+ std::to_string(this->width) + "|"
		+ std::to_string(this->length) + "|"
		+ std::to_string(this->depth);
}

Reservoir Reservoir::deserialize(const std::string& serializedObject)
{
	auto serializedParts = split(serializedObject, '|');

	return Reservoir{
		serializedParts[0],
		static_cast<Reservoir::ReservoirType>(std::stoi(serializedParts[1])),
		std::stod(serializedParts[2]),
		std::stod(serializedParts[3]),
		std::stod(serializedParts[4])
	};
}
