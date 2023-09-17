#include "iostream"
#include "Phone.h"
#include "cStrTools.h"

using namespace std;

namespace sdds {


    void searchByName(const char* partialName, FILE* file ){
        char name[51];
        char areaCode[6];
        char prefix[6];
        char number[6];

        while (fscanf(file, "%50[^\t]\t%4s\t%4s\t%4s\n", name, areaCode, prefix,number) != EOF) {
            char temporyPartialName[51], temporyName[51];
            toLowerCaseAndCopy(temporyPartialName, partialName);
            toLowerCaseAndCopy(temporyName, name);

            if (strStr(temporyName, temporyPartialName) != nullptr) {
                cout << name << ": (" << areaCode << ") " << prefix << "-" << number << endl ;
            }
        }
    }

    void phoneDir(const char* programTitle, const char* fileName) {

        cout << programTitle << " phone directory search" << endl;
        cout << "-------------------------------------------------------" << endl;

        FILE* file = fopen(fileName, "r");
        if (!file) {
            cout << "Error: Unable to open file " << fileName << endl;
            return;
        }

        char partialName[51];
        cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;

        while (true) {

            FILE* file2 = fopen(fileName, "r");

            cout << "> ";
            cin.getline(partialName, 51);

            if (strCmp(partialName, "!") == 0) {
                break;
            }
            searchByName(partialName, file2);
            fclose(file2);
        }


        cout << "Thank you for using " << programTitle << " directory." << endl;
    }
}
