// This class is a concrete strategy class of the strategy "IValueConverter", which is used to convert a shape to a row.

#pragma once

class StudentToRowConverter;

#include <memory>
#include <vector>

using std::shared_ptr;
using std::vector;

#include "IValueConverter.hpp"

class ShapeToRowConverter : public IValueConverter
{
public:
    ~ShapeToRowConverter() {};

private:
    vector<int> _widths;

public:
    string convert(shared_ptr<Object> object) override;

public:
    string toString() override { return "ShapeToRowConverter"; };
};