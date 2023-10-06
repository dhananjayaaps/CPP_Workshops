#include "Label.h"
#include <iostream>
#include <cstring>
#include <istream>

using namespace std;

namespace sdds{

    Label::Label() {
        setLabel(nullptr, nullptr);
    }

    Label::Label(const char *frameArg) {
        setLabel(frameArg, nullptr);
    }

    Label::Label(const char *frameArg, const char *content) {
        setLabel(frameArg, content);
    }

    Label::~Label() {
        delete [] m_content;
    }

    void Label::setContent(const char *content) {
        m_content = new char[strlen(content) + 1];
        strcpy(m_content, content);
    }

    void Label::setLabel(const char *frameArg, const char *content) {

        if(frameArg == nullptr){
            strcpy(m_frame, defaultFrame);
        } else{
            strcpy(m_frame, frameArg);
        }

        if (content){
            setContent(content);
        }
        else{
            m_content = nullptr;
        }
    }

    istream &Label::readLabel() {
        char input[71];
        cout << "> ";
        cin.getline(input, 71);
        setContent(input);
        return cin;
    }

    ostream& Label::printLabel() const {
        if(m_content){
            int len = strlen(m_content);
            int width = len + 4;
            cout << m_frame[0];
            for (int i = 0; i < width - 2; i++) {
                cout << m_frame[1];
            }
            cout << m_frame[2] << endl;

            cout << m_frame[7];
            for (int i = 0; i < width - 2; i++) {
                cout << ' ';
            }
            cout << m_frame[3] <<endl;

            cout << m_frame[7] << ' ' << m_content << ' ' << m_frame[3] << endl;

            cout << m_frame[7];
            for (int i = 0; i < width - 2; i++) {
                cout << ' ';
            }
            cout << m_frame[3] << endl;

            cout << m_frame[6];
            for (int i = 0; i < width - 2; i++) {
                cout << m_frame[5];
            }
            cout << m_frame[4];
            cout << endl;
        }
        return cout;
    }

    Label& Label::text(const char* contentArg) {
        setContent(contentArg);
        return *this;
    }
}


