#pragma once

class ISortingShapesStrategy;

#include <vector>

#include "Entity/Object.hpp"
#include "Entity/IShape.hpp"

using std::vector;

class ISortingShapesStrategy : public Object
{
public:
    virtual ~ISortingShapesStrategy() = default;

public:
    virtual void sort(vector<IShape*> &shapes) = 0;

public:
    string toString() override { return "ISortingShapesStrategy"; };
};