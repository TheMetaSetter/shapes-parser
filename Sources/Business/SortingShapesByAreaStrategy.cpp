#include "Business/SortingShapesByAreaStrategy.hpp"

#include <algorithm>

#include "Entity/IShape.hpp"

void SortingShapesByAreaStrategy::sort(vector<IShape*> &shapes)
{
    std::sort(shapes.begin(), shapes.end(), [](IShape* shape1, IShape* shape2) {
        return shape1->area() < shape2->area();
    });
}