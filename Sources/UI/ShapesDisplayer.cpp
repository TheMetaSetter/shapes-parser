#include <iostream>
#include <iomanip>

#include "UI/ShapesDisplayer.hpp"

using std::cout, std::endl;
using std::internal, std::setw;

mutex ShapesDisplayer::_mutex;
ShapesDisplayer* ShapesDisplayer::getInstance(IDisplayStrategy* displayStrategy)
{
    lock_guard<mutex> lock(_mutex);

    if (_instance == nullptr)
        _instance = new ShapesDisplayer(displayStrategy);

    return _instance;
}

void ShapesDisplayer::displayShapes(vector<IShape*> shapes)
{
    for (int i = 0; i < shapes.size(); i++)
    {
        cout << "| " << i + 1 << " | ";
        _displayStrategy->display(shapes[i]);
        cout << endl;
    }
}