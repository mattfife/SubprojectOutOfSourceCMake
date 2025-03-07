#include <iostream>

#include "main.h"
#include "class1.h"     // included from ../class1/include as specified in cmakefile.txt

int main(int argc, char** argv) 
{
    printf(message);

    // call code built into the class1 static library
    class1 c;
    c.callMe();

    return 0;
}