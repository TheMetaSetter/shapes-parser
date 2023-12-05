#pragma once

class SortingShapesPerformer;

#include "Entity/Object.hpp"
#include "ISortingShapesStrategy.hpp"

class SortingShapesPerformer : public Object
{
public:
    SortingShapesPerformer(ISortingShapesStrategy* sortingShapesStrategy) : _sortingShapesStrategy(sortingShapesStrategy) {};
    ~SortingShapesPerformer() {};

private:
    ISortingShapesStrategy* _sortingShapesStrategy;

public:
    void setSortingShapesStrategy(ISortingShapesStrategy* sortingShapesStrategy)
    {
        _sortingShapesStrategy = sortingShapesStrategy;
    }

    void performSorting(vector<IShape*> &shapes)
    {
        _sortingShapesStrategy->sort(shapes);
    }

public:
    string toString() override { return "SortingShapesPerformer"; };
};