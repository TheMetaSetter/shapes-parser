// This is a concrete strategy class of the strategy "IParsable".

#pragma once

class CircleParser;

#include <memory>

using std::shared_ptr, std::make_shared;

#include "Business/IParsable.hpp"

class CircleParser : public IParsable
{
public:
    ~CircleParser() {};

public:
    /**
     * @brief Returns the name of the object that is parsed by this parser. Can later be used in dependency injection.
     * 
     * @return string 
     */
    string parsedObjectName() override { return "Circle"; };

public:
    /**
     * @brief Parse a data string into an object.
     * 
     * @param data 
     * @return shared_ptr<Object> 
     */
    shared_ptr<Object> parse(string data) override;

public:
    string toString() override { return "CircleParser"; };
};