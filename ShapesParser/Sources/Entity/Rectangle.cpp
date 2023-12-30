#include "Entity/Rectangle.hpp"

Rectangle::Rectangle(double width, double height)
{
    _width = width;
    _height = height;

    calculatePerimeter();
    calculateArea();
}

double Rectangle::calculatePerimeter()
{
    _perimeter = 2 * (_width + _height);

    return _perimeter;
}

double Rectangle::calculateArea()
{
    _area = _width * _height;

    return _area;
}