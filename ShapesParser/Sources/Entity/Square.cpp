#include "Entity/Square.hpp"

Square::Square(double side)
{
    _rectangle = new Rectangle(side, side);

    _perimeter = _rectangle->perimeter();
    _area = _rectangle->area();
}

Square::~Square()
{
    delete _rectangle;
}

double Square::calculatePerimeter()
{
    return _perimeter;
}

double Square::calculateArea()
{
    return _area;
}