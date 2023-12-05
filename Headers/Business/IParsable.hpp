#pragma once

#include <string>

using std::string;

class IParsable;

#include "Entity/Object.hpp"

class IParsable : public Object
{
public:
    virtual ~IParsable() = default;

public:
    virtual string parsedObjectName() = 0;

public:
    virtual Object* parse(string data) = 0;

public:
    string toString() override { return "IParsable"; };
};