#include <memory>
#include <sstream>
#include <iomanip>
#include <string>

using std::shared_ptr, std::dynamic_pointer_cast;
using std::stringstream;
using std::setw, std::left, std::setprecision, std::fixed;
using std::to_string;

#include "UI/ShapeToRowConverter.hpp"
#include "Entity/IShape.hpp"

string ShapeToRowConverter::convert(shared_ptr<Object> object) {
    // If _widths is empty, then 3 widths to 0.
    if (_widths.empty()) {
        _widths = {0, 0, 0};
    }

    shared_ptr<IShape> shape = dynamic_pointer_cast<IShape>(object);

    // Use builder design pattern to build a row
    stringstream name;
    stringstream area;
    stringstream perimeter;

    area << "Area=" << fixed << setprecision(2) << shape->area();
    perimeter << "Perimeter=" << fixed << setprecision(2) << shape->perimeter();

    stringstream builder;
    builder
    << left << setw(_widths[0] - 2) << shape->toString() << " | "
    << left << setw(_widths[1] - 2) << area.str() << " | "
    << left << setw(_widths[2] - 2) << perimeter.str() << " |";

    return builder.str();
};