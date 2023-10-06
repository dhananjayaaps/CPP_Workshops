#include "LabelMaker.h"
#include <iostream>

using namespace std;

namespace sdds{

    LabelMaker::LabelMaker(int noOfLabels) {
        m_noOfLabels = noOfLabels;
    }

    void LabelMaker::readLabels() {

        m_labels = new Label[m_noOfLabels];
        for (int i = 0; i < m_noOfLabels; i++) {
            cout << "Enter label number " << i+1 << endl;
            m_labels[i].readLabel();
        }
    }

    LabelMaker::~LabelMaker() {
        delete [] m_labels;
    }

    void LabelMaker::printLabels() {

        for (int i = 0; i < m_noOfLabels; i++) {
            m_labels[i].printLabel();
        }
    }
}
