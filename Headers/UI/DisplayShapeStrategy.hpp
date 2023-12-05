#pragma once

class DisplayShapeStrategy;

#include "UI/IDisplayStrategy.hpp"

class DisplayShapeStrategy : public IDisplayStrategy
{
public:
    ~DisplayShapeStrategy() {};

public:
    void display(Object* object) override;

public:
    string toString() override { return "DisplayShapeStrategy"; };
};