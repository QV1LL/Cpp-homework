#pragma once

class LinearEquation : public Equation
{
protected:

	float juniorKoeficient;

public:

	LinearEquation(float juniorKoeficient, float freeKoeficient);

	virtual std::vector<float> getRoots() const override;

	virtual operator std::string() const;
};

