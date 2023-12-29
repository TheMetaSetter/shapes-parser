// This is an interface representing a general strategy to display a vector of shapes.

#pragma once

class IDisplayShapesStrategy;

#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;

#include "Entity/IShape.hpp"

class IDisplayShapesStrategy : public Object
{
public:
    virtual ~IDisplayShapesStrategy() = default;

public:
    /**
     * @brief A pure virtual function to display a vector of shapes. Every concrete strategy class must implement this function.
     * 
     * @param shapes 
     */
    virtual void display(vector<shared_ptr<Object>> shapes) = 0;

public:
    string toString() override { return "IDisplayShapesStrategy"; };
};