#pragma once

class CircleParser;

#include "Business/IParsable.hpp"

class CircleParser : public IParsable
{
public:
    ~CircleParser() {};

public:
    string parsedObjectName() override { return "Circle"; };

public:
    Object* parse(string data) override;

public:
    string toString() override { return "CircleParser"; };
};