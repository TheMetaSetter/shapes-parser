#pragma once

class ParserFactory;

#include <vector>
#include <map>
#include <exception>

#include "Business/IParsable.hpp"
#include "Entity/Object.hpp"
#include "Business/RectangleParser.hpp"
#include "Business/SquareParser.hpp"
#include "Business/CircleParser.hpp"

using std::map;
using std::invalid_argument;
using std::vector;
class ParserFactory : public Object
{
public:
    ~ParserFactory() {};

private:
    // Using dependency injection
    map<string, shared_ptr<IParsable>> _abilities;

public:
    // Inject abilities through constructor into the factory
    ParserFactory()
    {
        vector<shared_ptr<IParsable>> parsers = {
            make_shared<RectangleParser>(),
            make_shared<SquareParser>(),
            make_shared<CircleParser>()
        };

        for (shared_ptr<IParsable> parser : parsers)
        {
            _abilities[parser->parsedObjectName()] = parser;
        }
    }

    shared_ptr<IParsable> create(string objectName)
    {
        if (_abilities.contains(objectName))
        {
            return _abilities[objectName];
        }
        else
        {
            throw invalid_argument("ParserFactory: No parser for " + objectName);
        }
    }

public:
    string toString() override { return "ParserFactory"; };
};