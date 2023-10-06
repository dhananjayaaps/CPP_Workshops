#ifndef DIY_LABELMAKER_H
#define DIY_LABELMAKER_H

#include "Label.h"

namespace sdds{

    class LabelMaker {

        int m_noOfLabels{};
        Label *m_labels;

    public:
        LabelMaker(int noOfLabels);
        void readLabels();
        void printLabels();
        ~LabelMaker();
    };
}

#endif //DIY_LABELMAKER_H
