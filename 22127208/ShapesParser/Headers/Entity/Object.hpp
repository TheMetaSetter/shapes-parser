#pragma once

#include <string>

using std::string;

class Object;

class Object
{
public:
    virtual ~Object() {};

public:
    /**
     * @brief Return keyword (type) of object
     * 
     * @return string: keyword (type) of object
     */
    virtual string toString() = 0;
};