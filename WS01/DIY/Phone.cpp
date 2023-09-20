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
            char tempPartialName[51], tempName[51];
            toLowerCaseAndCopy(tempPartialName, partialName);
            toLowerCaseAndCopy(tempName, name);

            if (strStr(tempName, tempPartialName) != nullptr) {
                cout << name << ": (" << areaCode << ") " << prefix << "-" << number << endl ;
            }
        }
    }

    void phoneDir(const char* programTitle, const char* fileName) {

        cout << programTitle << " phone directory search" << endl;
        cout << "-------------------------------------------------------" << endl;

        FILE* file = fopen(fileName, "r");
        if (!file) {
            cout << fileName <<" file not found!"<< endl;
            cout << "Thank you for using " << programTitle << " directory." << endl;
            return;
        }

        char partialName[51];

        while (true) {
            cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
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