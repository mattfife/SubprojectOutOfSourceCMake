#include <iostream>
#include "include//class1.h"

const char* class1_message = " class1 message A";

bool class1::callMe()
{
    std::cout << class1_message << std::endl;
    return true;
}