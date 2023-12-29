// This is a context class of the strategy "ISortingShapesStrategy", which can be used in Visitor Design Pattern later.

#pragma once

#include <map>
#include <exception>

using std::map;
using std::invalid_argument;

class SortingShapesPerformer;

#include "Entity/Object.hpp"
#include "ISortingShapesStrategy.hpp"
#include "Business/SortingShapesByAreaStrategy.hpp"

class Criteria
{
public:
    inline static const string AREA = "area";
};

class SortingShapesPerformer : public Object
{
public:
    // Using dependency injection to inject abilities through constructor into the context
    SortingShapesPerformer()
    {
        _abilities[Criteria::AREA] = make_shared<SortingShapesByAreaStrategy>();
    }

    ~SortingShapesPerformer() {};

public:
    map<string, shared_ptr<ISortingShapesStrategy>> _abilities;

public:
    void performSorting(vector<shared_ptr<Object>> &shapes, string criteria)
    {
        if (_abilities.contains(criteria))
        {
            _abilities[criteria]->sort(shapes);
        }
        else
        {
            throw invalid_argument("Invalid criteria");
        }
    }

public:
    string toString() override { return "SortingShapesPerformer"; };
};