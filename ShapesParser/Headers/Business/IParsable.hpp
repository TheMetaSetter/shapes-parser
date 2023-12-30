// This is an interface representing a general strategy to parse a string into an object.

#pragma once

#include <string>
#include <memory>

using std::string;
using std::shared_ptr, std::make_shared;

class IParsable;

#include "Entity/Object.hpp"

class IParsable : public Object
{
public:
    virtual ~IParsable() = default;

public:
    /**
     * @brief Returns the name of the object that is parsed by this parser. Can later be used in dependency injection.
     * 
     * @return string: the name of the object that is parsed by this parser.
     */
    virtual string parsedObjectName() = 0;

public:
    /**
     * @brief Parse a data string into an object.
     * 
     * @param data is the string to be parsed.
     * @return shared_ptr<Object>: the parsed object.
     */
    virtual shared_ptr<Object> parse(string data) = 0;

public:
    string toString() override { return "IParsable"; };
};