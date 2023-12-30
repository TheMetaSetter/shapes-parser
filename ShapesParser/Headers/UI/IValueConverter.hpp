#pragma once

class IValueConverter;

#include <memory>

using std::shared_ptr;

#include <Entity/Object.hpp>

class IValueConverter : public Object
{
public:
    ~IValueConverter() {};

public:
    /**
     * @brief A pure virtual function to convert an object to a string. Every concrete converter class must implement this function.
     * 
     * @param object 
     * @return string 
     */
    virtual string convert(shared_ptr<Object> object) = 0;

public:
    string toString() override { return "IValueConverter"; };
};