#pragma once

#include "Entity/Object.hpp"

using std::lock_guard, std::mutex;

class IDisplayStrategy : public Object
{
public:
    virtual ~IDisplayStrategy() = default;

public:
    virtual void display(Object* object) = 0;

public:
    string toString() override { return "IDisplayStrategy"; };
};