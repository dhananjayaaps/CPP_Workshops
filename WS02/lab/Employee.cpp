/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  Employee.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#include <iostream>
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

   int noOfEmployees;
   Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }


    bool load(Employee& emp) {
        emp.m_name = nullptr;
        if (read(emp.m_empNo) && read(emp.m_salary) && read(emp.m_name)) {
            return true;
        }
        return false;
    }


    bool load() {
        if (!openFile(DATAFILE)) {
            return false;
        }

        noOfEmployees = noOfRecords();

        if (noOfEmployees <= 0) {
            std::cerr << "Error: incorrect number of records read; the data is possibly corrupted." << std::endl;
            closeFile();
            return false;
        }

        employees = new Employee[noOfEmployees];

        for (int i = 0; i < noOfEmployees; i++) {
            if (!load(employees[i])) {
                std::cerr << "Error: failed to load employee data." << std::endl;
                closeFile();
                deallocateMemory();
                return false;
            }
        }

        closeFile();
        return true;
    }

    void display(const Employee& emp) {
        std::cout << emp.m_empNo << ": " << emp.m_name << ", $" << static_cast<int>(emp.m_salary) << std::endl;
    }


    void display() {
        std::cout << "Employee Salary report, sorted by employee number" << std::endl;
        std::cout << "no- Empno, Name, Salary" << std::endl;
        std::cout << "------------------------------------------------" << std::endl;
        sort();
        for (int i = 0; i < noOfEmployees; i++) {
            std::cout << i + 1 << "- ";
            display(employees[i]);
        }
    }


   void deallocateMemory() {
       if (employees != nullptr) {
           for (int i = 0; i < noOfEmployees; i++) {
               delete[] employees[i].m_name;
           }
           delete[] employees;
       }
   }
}