#pragma once

class Table;

#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;

#include "Entity/Object.hpp"
#include "IValueConverter.hpp"

class Table : public Object
{
public:
    ~Table() {};

public:
    Table(vector<string> headers, vector<int> widths, vector<shared_ptr<Object>> data, shared_ptr<IValueConverter> converter);

private:
    Table();
    vector<string> _headers;
    vector<int> _widths;
    vector<shared_ptr<Object>> _data;
    shared_ptr<IValueConverter> _converter;

public:
    void display();

public:
    string toString() override { return "Table"; };
};