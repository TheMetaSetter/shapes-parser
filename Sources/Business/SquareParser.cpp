#include "Business/SquareParser.hpp"
#include "Entity/Square.hpp"
#include "Helper/Utils.hpp"

shared_ptr<Object> SquareParser::parse(string data)
{
    // a=12
    vector<string> tokens = Utils::String::split(data, "=");

    double edge = stod(tokens[1]);

    return make_shared<Square>(edge);
}