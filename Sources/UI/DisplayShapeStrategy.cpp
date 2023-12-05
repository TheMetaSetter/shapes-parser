#include <iostream>
#include <iomanip>
#include <sstream>

#include "UI/DisplayShapeStrategy.hpp"
#include "Entity/IShape.hpp"

using std::cout, std::endl;
using std::fixed, std::setw, std::left, std::setprecision;
using std::stringstream;

using std::setw, std::fixed;

void DisplayShapeStrategy::display(Object* object)
{
    IShape* shape = dynamic_cast<IShape*>(object);
    stringstream builder;

    // Square       | Perimeter=10.1 | Area=12.24 |
    builder << left << fixed << setw(13) << shape->toString() << "| "
            << "Perimeter=" << setw(2) << setprecision(1) << shape->perimeter() << " | "
            << "Area=" << setw(2) << setprecision(2) << shape->area() << " |";
    
    string result = builder.str();

    cout << result << endl;
}