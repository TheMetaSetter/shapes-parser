#pragma once

class RectangleParser;

#include "IParsable.hpp"

class RectangleParser : public IParsable
{
public:
    ~RectangleParser() {};

public:
    string parsedObjectName() override { return "Rectangle"; };

public:
    Object* parse(string data) override;

public:
    string toString() override { return "RectangleParser"; };
};