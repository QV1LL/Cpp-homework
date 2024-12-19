#include "Banana.h"

std::ostream& Banana::operator<<(std::ostream& out)
{
	out << static_cast<Fruit&>(*this);

	return out;
}