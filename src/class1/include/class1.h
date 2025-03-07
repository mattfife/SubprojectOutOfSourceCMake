#pragma once
#include <iostream>

extern const char* class1_message;

class class1
{
    public:
    class1()
    {
        std::cout << " class1 constructor" << std::endl;
    }

    ~class1()
    {
        std::cout << " class1 destructor" << std::endl;
    }

    bool callMe();
};
