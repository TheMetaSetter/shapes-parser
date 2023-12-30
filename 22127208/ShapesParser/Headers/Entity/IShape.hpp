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
    /**
     * @brief Get perimeter of shape
     * 
     * @return double: perimeter of shape
     */
    double perimeter();

    /**
     * @brief Get area of shape
     * 
     * @return double: area of shape
     */
    double area();

public:
    /**
     * @brief Calculate perimeter of shape
     * 
     * @return double: perimeter of shape
     */
    virtual double calculatePerimeter() = 0;

    /**
     * @brief Calculate area of shape
     * 
     * @return double: area of shape
     */
    virtual double calculateArea() = 0;

public:
    string toString() override { return "IShape"; };
};