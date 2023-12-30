// This is a context class of the strategy "IDisplayShapesStrategy", which can be used in Visitor Design Pattern later.

#pragma once

class ShapesDisplayer;

#include <vector>
#include <mutex>
#include <memory>
#include <map>
#include <exception>

using std::vector;
using std::lock_guard, std::mutex;
using std::shared_ptr, std::make_shared;
using std::map;
using std::invalid_argument;

#include "IDisplayShapesStrategy.hpp"
#include "DisplayShapesTableStrategy.hpp"
#include "Entity/IShape.hpp"

class DisplayMode
{
public:
    inline static string TABLE = "DisplayShapesTableStrategy";
};

class ShapesDisplayer : public Object
{
public:
    ~ShapesDisplayer() {};

// This class uses Thread-Safe Singleton Design Pattern.
private:
    // ShapesDisplayer(const ShapesDisplayer&);
    // ShapesDisplayer(ShapesDisplayer&&);
    // ShapesDisplayer& operator=(const ShapesDisplayer&) = delete;
    // ShapesDisplayer& operator=(ShapesDisplayer&&) = delete;

private:
    inline static shared_ptr<ShapesDisplayer> _instance = nullptr;
    static mutex _mutex;

public:
    static shared_ptr<ShapesDisplayer> getInstance();

private:
    map<string, shared_ptr<IDisplayShapesStrategy>> _strategies;

public:
    // Dependency injection
    void signWith(shared_ptr<IDisplayShapesStrategy> strategy)
    {
        _strategies.insert({strategy->toString(), strategy});
    }

    void display(vector<shared_ptr<Object>> shapes, string mode)
    {
        if (_strategies.contains(mode))
        {
            _strategies[mode]->display(shapes);
        }
        else
        {
            throw invalid_argument("Invalid display mode. Please select mode by typing \"DisplayMode::\"");
        }
    }

public:
    string toString() override { return "ShapesDisplayer"; };
};