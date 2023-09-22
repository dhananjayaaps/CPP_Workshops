/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"
#include <cstring>

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }

    bool read(char*& name) {
        char buffer[128];
        if (fscanf(fptr, "%127[^\n]\n", buffer) == 1) {
            int len = strlen(buffer) + 1;
            name = new char[len];
            strcpy(name, buffer);

            return true;
        }
        return false;
    }


    bool read(int& empNo) {
        if (fscanf(fptr, "%d,", &empNo) == 1) {
            return true;
        }
        return false;
    }

    bool read(double& salary) {
        if (fscanf(fptr, "%lf,", &salary) == 1) {
            return true;
        }
        return false;
    }

}