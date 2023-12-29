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
    /**
     * @brief Parse a data string into an object.
     * 
     * @param data 
     * @return shared_ptr<Object> 
     */
    shared_ptr<Object> parse(string data) override;

public:
    string toString() override { return "SquareParser"; };
};