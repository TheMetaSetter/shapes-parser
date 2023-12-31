#pragma once

class Rectangle;

#include "IShape.hpp"

class Rectangle : public IShape
{
public:
    ~Rectangle() {};

private:
    double _width;
    double _height;
    Rectangle();

public:
    /**
     * @brief Construct a new Rectangle object
     * 
     * @param width is the width of rectangle
     * @param height is the height of rectangle
     */
    Rectangle(double width, double height);
    
public:
    double calculatePerimeter() override;
    double calculateArea() override;

public:
    string toString() override { return "Rectangle"; };
};