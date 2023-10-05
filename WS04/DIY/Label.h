#ifndef DIY_LABEL_H
#define DIY_LABEL_H

const char defaultFrame[] = "+-+|+-+|";

namespace sdds{
    class Label {

    private:

        char *m_conent;
        char m_frame[9];

    public:
        Label();
        Label(const char* frameArg);
        ~Label();


    };
}



#endif //DIY_LABEL_H
