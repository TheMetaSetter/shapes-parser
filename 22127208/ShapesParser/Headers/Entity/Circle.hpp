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
    /**
     * @brief Construct a new Circle object
     * 
     * @param radius is the radius of circle
     
     */
    Circle(double radius);

public:
    double calculatePerimeter() override;
    double calculateArea() override;

public:
    string toString() override { return "Circle"; };
};