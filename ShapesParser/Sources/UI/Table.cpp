#include <exception>
#include <sstream>
#include <iomanip>
#include <iostream>

using std::invalid_argument;
using std::stringstream;
using std::setw, std::right;
using std::cout, std::endl;

#include "UI/Table.hpp"
#include "Helper/Utils.hpp"

Table::Table(vector<string> headers, vector<int> widths, vector<shared_ptr<Object>> data, shared_ptr<IValueConverter> converter)
{
    _headers = headers;
    _widths = widths;
    _data = data;
    _converter = converter;
}

void Table::display()
{
    if (_headers.size() > 0 && _headers.size() != _widths.size())
    {
        throw invalid_argument("The number of headers must be equal to the number of widths.");
    }

    // If any of the widths is negative. throw an exception.
    if (Utils::Vector::hasNegative(_widths))
    {
        throw invalid_argument("A width cannot be negative.");
    }

    // Display the table
    // Display headers
    if (_headers.size() >= 1)
    {
        stringstream builder;
        int lastIndex = _headers.size() - 1;
        for (int i = 0; i < lastIndex; i++)
        {
            builder << setw(_widths[i]) << right << _headers[i] << "| ";
        }
        builder << setw(_widths[lastIndex]) << right << _headers[lastIndex] << "|";
        cout << builder.str() << endl;
    }

    // Display data
    for (int i = 0; i < _data.size(); i++)
    {
        string row = _converter->convert(_data[i]);
        stringstream builder;
        builder << "| " << i + 1 << " | " << row;
        cout << builder.str() << endl;
    }
}