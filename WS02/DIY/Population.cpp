/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#include "iostream"
#include "Population.h"
#include "File.h"
#include <cstring>

using namespace std;

namespace sdds {
   bool startsWith(const char* cstring, const char* subString) {
      return std::strstr(cstring, subString) == cstring;
   }

   bool getPostalCode(char* postal_code_prefix) {
       cout << "Population Report" << endl;
       cout << "-----------------"<< endl;
       cout << " Enter Postal code: " << endl;
       cout << "> ";
       cin >> postal_code_prefix ;
       if (postal_code_prefix[0] == '!'){
           return false;
       }
       return true;
   }

//   bool load(const char* filename){
//       return openFile(filename);
//   }




    bool load(const char* filename, const char* partial_postal_code_prefix) {
        char postalCode[4];
        int population;
        if (openFile(filename) ) {
            FILE* file = fopen(filename, "r");
            while(fscanf(file, "%[^,],%d\n", postalCode, &population) == 2){

            }

        }

    }




}