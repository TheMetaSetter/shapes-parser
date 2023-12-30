#pragma once

class Circle;

#include "Entity/IShape.hpp"

class Circle : public IShape
{
public:
    ~Circle() {};

private:
    double _radius;

public:
    Circle(double radius);

public:
    double calculatePerimeter() override;
    double calculateArea() override;

public:
    string toString() override { return "Circle"; };
};