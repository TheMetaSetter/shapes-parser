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
    /**
     * @brief Construct a new Square object
     * 
     * @param side is the side of square
     
     */
    Square(double side);

public:
    double calculatePerimeter() override;
    double calculateArea() override;

public:
    string toString() override { return "Square"; };
};