#pragma once

class SortingShapesByAreaStrategy;

#include <vector>

#include "ISortingShapesStrategy.hpp"

class SortingShapesByAreaStrategy : public ISortingShapesStrategy
{
public:
    ~SortingShapesByAreaStrategy() {};

public:
    void sort(vector<IShape*> &shapes) override;

public:
    string toString() override { return "SortingShapesByAreaStrategy"; };
};