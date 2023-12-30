#pragma once

class Square;

#include "IShape.hpp"
#include "Rectangle.hpp"

class Square : public IShape
{
public:
    ~Square();

private:
    Rectangle* _rectangle;

public:
    Square(double side);

public:
    double calculatePerimeter() override;
    double calculateArea() override;

public:
    string toString() override { return "Square"; };
};