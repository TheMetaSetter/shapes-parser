// This is an interface representing a general strategy to sort a vector of shapes.

#pragma once

class ISortingShapesStrategy;

#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr, std::make_shared;

#include "Entity/Object.hpp"
#include "Entity/IShape.hpp"

class ISortingShapesStrategy : public Object
{
public:
    virtual ~ISortingShapesStrategy() = default;

public:
    /**
     * @brief 
     * 
     * @param shapes 
     */
    virtual void sort(vector<shared_ptr<Object>> &shapes) = 0;

public:
    string toString() override { return "ISortingShapesStrategy"; };
};