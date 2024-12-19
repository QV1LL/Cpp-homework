#include "Fruit.h"

std::ostream& operator<<(std::ostream& out, const Fruit& fruit)
{
	out << fruit.color << " " << fruit.name;

	return out;
}
