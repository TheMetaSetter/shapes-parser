#pragma once

class ShapesDisplayer;

#include <vector>
#include <mutex>

#include "IDisplayStrategy.hpp"
#include "Entity/IShape.hpp"

using std::vector;
using std::lock_guard, std::mutex;

class ShapesDisplayer : public Object
{
public:
    ShapesDisplayer() = delete;
    ShapesDisplayer(const ShapesDisplayer&) = delete;
    ShapesDisplayer(ShapesDisplayer&&) = delete;
    ShapesDisplayer& operator=(const ShapesDisplayer&) = delete;
    ShapesDisplayer& operator=(ShapesDisplayer&&) = delete;

private:
    inline static ShapesDisplayer* _instance = nullptr;
    static mutex _mutex;

public:
    static ShapesDisplayer* getInstance(IDisplayStrategy* displayStrategy);

public:
    ShapesDisplayer(IDisplayStrategy* displayStrategy) : _displayStrategy(displayStrategy) {};
    ~ShapesDisplayer() {};

private:
    IDisplayStrategy* _displayStrategy;

public:
    void setStrategy(IDisplayStrategy* displayStrategy) { _displayStrategy = displayStrategy; };
    void displayShapes(vector<IShape*> shapes);

public:
    string toString() override { return "ShapesDisplayer"; };
};