#include "iostream"
#include "Phone.h"
#include "cStrTools.h"

using namespace std;

namespace sdds {

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
            cout << "> ";
            cin.getline(partialName, 51);

            if (strCmp(partialName, "!") == 0) {
                break;
            }
            searchByName(partialName, file);
        }

        fclose(file);
        cout << "Thank you for using " << programTitle << " directory." << endl;
    }
}
