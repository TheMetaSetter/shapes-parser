#include "Business/SortingShapesByAreaStrategy.hpp"

#include <algorithm>

#include "Entity/IShape.hpp"

void SortingShapesByAreaStrategy::sort(vector<shared_ptr<Object>> &shapes)
{
    std::sort(shapes.begin(), shapes.end(), [](shared_ptr<Object> shape1, shared_ptr<Object> shape2) {
        return dynamic_pointer_cast<IShape>(shape1)->area() < dynamic_pointer_cast<IShape>(shape2)->area();
    });
}