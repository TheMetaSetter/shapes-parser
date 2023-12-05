#pragma once

#include <string>

using std::string;

class Object;

class Object
{
public:
    virtual ~Object() {};

public:
    virtual string toString() = 0;
};