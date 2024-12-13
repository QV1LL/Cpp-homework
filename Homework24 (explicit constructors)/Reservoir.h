#pragma once

class Reservoir
{
private:

	enum class ReservoirType;


	std::string name;
	ReservoirType reservoirType;

	double width;
	double length;
	double depth;

public:

	Reservoir() : name("reservoir"), reservoirType(ReservoirType::POOL), width(1), length(1), depth(1)
	{

	}

	explicit Reservoir(const char* name) : name(name), reservoirType(ReservoirType::POOL), width(1), length(1), depth(1)
	{

	}

	Reservoir(const std::string& name,
		ReservoirType reservoirType, 
		double width,
		double length, 
		double depth);

	double getSquare() const;
	double getVolume() const;
	bool isSquareBigger(const Reservoir& other) const;
	std::string toString() const;

	bool operator== (const Reservoir& other) const;
	Reservoir& operator= (const Reservoir& other);

	std::string serialize() const;
	static Reservoir deserialize(const std::string& serializedObject);

	enum class ReservoirType 
	{
		SEA,
		POOL,
		POND,
		LAKE,
	};
};

