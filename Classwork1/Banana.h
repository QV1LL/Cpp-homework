#pragma once
#include "Fruit.h"

class Banana :
    public Fruit
{
public:

    Banana(const std::string& name, const std::string& color)
        : Fruit(name, color)
    {

    }

    std::ostream& operator<< (std::ostream& out);
};

