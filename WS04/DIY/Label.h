#ifndef DIY_LABEL_H
#define DIY_LABEL_H

#include <iostream>

const char defaultFrame[] = "+-+|+-+|";

namespace sdds{
    class Label {

    private:

        char *m_content{};
        char m_frame[9]{};

    public:
        Label();
        Label(const char* frameArg);
        Label(const char* frameArg, const char* content);
        void setLabel(const char* frameArg, const char* content);
        void setContent(const char* content);
        ~Label();
        std::istream& readLabel();
        std::ostream& printLabel()const;
        Label& text(const char* contentArg);

    };

}



#endif //DIY_LABEL_H
