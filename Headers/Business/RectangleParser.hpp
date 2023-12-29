#pragma once

class RectangleParser;

#include "IParsable.hpp"

class RectangleParser : public IParsable
{
public:
    ~RectangleParser() {};

public:
    /**
     * @brief Returns the name of the object that is parsed by this parser. Can later be used in dependency injection.
     * 
     * @return string
     */
    string parsedObjectName() override { return "Rectangle"; };

public:
    /**
     * @brief Parse a data string into an object.
     * 
     * @param data 
     * @return shared_ptr<Object> 
     */
    shared_ptr<Object> parse(string data) override;

public:
    string toString() override { return "RectangleParser"; };
};