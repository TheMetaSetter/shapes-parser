#include <iostream>
#include <iomanip>

#include "UI/ShapesDisplayer.hpp"

using std::cout, std::endl;
using std::internal, std::setw;

mutex ShapesDisplayer::_mutex;
shared_ptr<ShapesDisplayer> ShapesDisplayer::getInstance()
{
    lock_guard<mutex> lock(_mutex);

    if (_instance == nullptr)
    {
        _instance = make_shared<ShapesDisplayer>();
    }

    return _instance;
}