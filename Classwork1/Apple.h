#pragma once
#include "Fruit.h"

class Apple :
    public Fruit
{
private:

    double fiber;

public:

    Apple(const std::string& name, const std::string& color, double fiber)
        : Fruit(name, color), fiber(fiber) 
    {

    }

    std::ostream& operator<< (std::ostream& out);
};

