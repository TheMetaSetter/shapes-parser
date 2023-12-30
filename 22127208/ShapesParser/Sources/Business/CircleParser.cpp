#include "Business/CircleParser.hpp"
#include "Entity/Circle.hpp"
#include "Helper/Utils.hpp"

shared_ptr<Object> CircleParser::parse(string data)
{
    // r=17
    vector<string> tokens = Utils::String::split(data, "=");

    double radius = stod(tokens[1]);

    return make_shared<Circle>(radius);
}