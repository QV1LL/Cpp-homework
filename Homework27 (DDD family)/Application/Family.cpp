#include <iostream>
#include <vector>

#include "Family.h"

int Project::Family::ID_COUNTER = 0;
int Project::Family::MAX_CHILDREN_COUNT = 5;

Project::Family::Family(Parent father, Parent mother)
	: father(father), mother(mother)
{
	this->id = ID_COUNTER++;
}
