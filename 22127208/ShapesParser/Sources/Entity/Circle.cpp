#include <math.h>

#include "Entity/Circle.hpp"

using std::pow;

Circle::Circle(double radius)
{
    _radius = radius;

    calculatePerimeter();
    calculateArea();
}

double Circle::calculatePerimeter()
{
    _perimeter = 2 * M_PI * _radius;

    return _perimeter;
}

double Circle::calculateArea()
{
    _area = M_PI * pow(_radius, 2);

    return _area;
}