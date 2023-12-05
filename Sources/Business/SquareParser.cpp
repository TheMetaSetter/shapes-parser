#include "Business/SquareParser.hpp"
#include "Entity/Square.hpp"
#include "Helper/Utils.hpp"

Object* SquareParser::parse(string data)
{
    // a=12
    vector<string> tokens = Utils::String::split(data, "=");

    double edge = stod(tokens[1]);

    return new Square(edge);
}