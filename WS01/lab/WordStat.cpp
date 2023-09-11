#include <iostream>
#include "Word.h"
#include "Word.h" // This is intentional
using namespace sdds;
using namespace std;

int main() {
    char filename[256];
    programTitle();
    cout << "Enter filename: ";
    cin >> filename;
    wordStats(filename);
    return 0;
}