#include "Apple.h"

std::ostream& Apple::operator<<(std::ostream& out)
{
	out << static_cast<Fruit&>(*this);
	out << this->fiber;

	return out;
}
