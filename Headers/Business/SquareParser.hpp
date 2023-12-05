#pragma once

class SquareParser;

#include "Business/IParsable.hpp"

class SquareParser : public IParsable
{
public:
    ~SquareParser() {};

public:
    string parsedObjectName() override { return "Square"; };

public:
    Object* parse(string data) override;

public:
    string toString() override { return "SquareParser"; };
};