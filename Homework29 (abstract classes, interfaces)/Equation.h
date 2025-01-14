#pragma once

class Equation
{
protected:

	float freeKoeficient;

public:

	explicit Equation(float freeKoeficient);

	virtual std::vector<float> getRoots() const = 0;

	virtual operator std::string() const;

	virtual ~Equation() = default;

};

