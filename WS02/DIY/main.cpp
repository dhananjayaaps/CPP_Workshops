/***********************************************************************
// OOP244 Workshop #2 DIY (part 2): tester program
//
// File  main.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
//#include "Population.h"
//using namespace sdds;
//int main() {
//   if (load("PCpopulations.csv")) {
//      display();
//   }
//   deallocateMemory();
//   return 0;
//}

#include <iostream>
#include "Population.h"
using namespace sdds;
int main() {
    char code[4]{};
    while(getPostalCode(code)){
        if(load("PCpopulations.csv", code)) {
            display();
        }
        deallocateMemory();
    }
    return 0;
}