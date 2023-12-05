#include "Business/RectangleParser.hpp"
#include "Entity/Rectangle.hpp"
#include "Helper/Utils.hpp"

Object* RectangleParser::parse(string data)
{
    // w=3, h=4
    vector<string> tokens = Utils::String::split(data, ",");

    string widthStr = Utils::String::split(tokens[0], "=")[1];
    string heightStr = Utils::String::split(tokens[1], "=")[1];

    return new Rectangle(stod(widthStr), stod(heightStr));
}