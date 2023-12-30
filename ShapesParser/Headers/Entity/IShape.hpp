#pragma once

class IShape;

#include "Object.hpp"

class IShape : public Object
{
public:
    virtual ~IShape() = default;

protected:
    double _perimeter;
    double _area;

public:
    double perimeter();
    double area();

public:
    virtual double calculatePerimeter() = 0;
    virtual double calculateArea() = 0;

public:
    string toString() override { return "IShape"; };
};