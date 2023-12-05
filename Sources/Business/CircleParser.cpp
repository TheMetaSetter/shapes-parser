#include "Business/CircleParser.hpp"
#include "Entity/Circle.hpp"
#include "Helper/Utils.hpp"

Object* CircleParser::parse(string data)
{
    // r=17
    vector<string> tokens = Utils::String::split(data, "=");

    double radius = stod(tokens[1]);

    return new Circle(radius);
}