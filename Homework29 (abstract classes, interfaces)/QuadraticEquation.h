#pragma once

class QuadraticEquation : public LinearEquation
{
private:

	float seniorKoeficient;

public:

	QuadraticEquation(float seniorKoeficient,
		float juniorKoeficient,
		float freeKoeficient);

	virtual std::vector<float> getRoots() const override;

	virtual operator std::string() const;
};

