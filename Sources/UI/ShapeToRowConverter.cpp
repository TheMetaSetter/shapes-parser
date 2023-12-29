#include <memory>
#include <sstream>
#include <iomanip>

using std::shared_ptr, std::dynamic_pointer_cast;
using std::stringstream;
using std::setw, std::left, std::setprecision, std::fixed;

#include "UI/ShapeToRowConverter.hpp"
#include "Entity/IShape.hpp"

string ShapeToRowConverter::convert(shared_ptr<Object> object) {
    // If _widths is empty, then 3 widths to 0.
    if (_widths.empty()) {
        _widths = {0, 0, 0};
    }

    shared_ptr<IShape> shape = dynamic_pointer_cast<IShape>(object);

    // Use builder design pattern to build a row
    stringstream builder;

    builder << setprecision(2) << fixed << left
    << setw(_widths[0]) << shape->toString() << " | "
    << setw(_widths[1]) << "Perimeter=" << shape->perimeter() << " | "
    << setw(_widths[2]) << "Area=" << shape->area() << " |";

    return builder.str();
};