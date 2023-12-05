#pragma once

class ParserFactory;

#include <map>

#include "Business/IParsable.hpp"
#include "Entity/Object.hpp"

using std::map;

class ParserFactory : public Object
{
public:
    ~ParserFactory() {};

private:
    // Using dependency injection
    map<string, IParsable*> _abilities;

public:
    // Inject abilities into the factory
    void registerWith(IParsable* parser)
    {
        _abilities.insert(
            {parser->parsedObjectName(), parser}
        );
    }

    IParsable* create(string objectName)
    {
        return _abilities[objectName];
    }

public:
    string toString() override { return "ParserFactory"; };
};