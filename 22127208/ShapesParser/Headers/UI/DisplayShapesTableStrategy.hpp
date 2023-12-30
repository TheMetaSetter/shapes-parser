// This is a concrete strategy class of the strategy "IDisplayShapesStrategy", which is used to display a vector of shapes in a table.

#pragma once

class DisplayShapesTableStrategy;

#include <memory>

using std::shared_ptr, std::make_shared;

#include "IDisplayShapesStrategy.hpp"
#include "ShapeToRowConverter.hpp"
#include "Table.hpp"

class DisplayShapesTableStrategy : public IDisplayShapesStrategy
{
public:
    ~DisplayShapesTableStrategy() {};

private:
    vector<string> _headers;
    vector<int> _widths;

public:
    DisplayShapesTableStrategy(vector<string> headers, vector<int> widths)
    {
        _headers = headers;
        _widths = widths;
    }

public:
    /**
     * @brief Display a vector of shapes in a table.
     * 
     * @param shapes
     */
    void display(vector<shared_ptr<Object>> shapes) override
    {
        shared_ptr<IValueConverter> converter = make_shared<ShapeToRowConverter>(_widths);
        Table table(_headers, _widths, shapes, converter);
        table.display();
    }

public:
    string toString() override { return "DisplayShapesTableStrategy"; };
};