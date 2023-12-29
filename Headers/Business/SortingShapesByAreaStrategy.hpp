// This is a concrete strategy class of the strategy "ISortingShapesStrategy", which is used to sort a vector of shapes by their area.

#pragma once

class SortingShapesByAreaStrategy;

#include <vector>

#include "ISortingShapesStrategy.hpp"

class SortingShapesByAreaStrategy : public ISortingShapesStrategy
{
public:
    ~SortingShapesByAreaStrategy() {};

public:
    void sort(vector<shared_ptr<Object>> &shapes) override;

public:
    string toString() override { return "SortingShapesByAreaStrategy"; };
};