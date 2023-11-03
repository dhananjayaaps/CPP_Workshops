#include <iostream>
#include <iomanip>
#include <cstring>
#include "HealthCard.h"
using namespace std;
namespace sdds {

    HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]) {
        set(name, number, vCode, sNumber);
    }

    HealthCard::HealthCard(const HealthCard& hc) {
        if (hc) {
            set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
        } else {
            setEmpty();
        }
    }

    HealthCard& HealthCard::operator=(const HealthCard& hc) {
        if (this != &hc) {
            if (hc) {
                set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
            } else {
                setEmpty();
            }
        }
        return *this;
    }

    HealthCard::~HealthCard() {
        delete[] m_name;
    }

    HealthCard::operator bool() const {
        return m_name != nullptr;
    }

    std::ostream& HealthCard::printIDInfo(std::ostream& ostr) const {
        ostr << m_number << '-' << m_vCode << ", " << m_sNumber;
        return ostr;
    }

    std::ostream& HealthCard::print(std::ostream& ostr, bool toFile) const {
        if (*this) {
            if (toFile) {
                ostr << m_name << ",";
                printIDInfo(ostr);
                ostr << "\n";
            } else {
                ostr << std::left << std::setfill('.') << std::setw(50) << m_name;
                printIDInfo(ostr);
            }
        } else {
            if(!toFile){
                ostr << "Invalid Health Card Record";
            }
        }
        return ostr;
    }

    void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[]) {
        if (validID(name, number, vCode, sNumber)) {
            allocateAndCopy(name);
            m_number = number;
            std::strncpy(m_vCode, vCode, 3);
            std::strncpy(m_sNumber, sNumber, 10);
        } else {
            setEmpty();
        }
    }

    bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const {

        if (name == nullptr || std::strlen(name) == 0) {
            return false;
        }
        if (number <= 999999999 || number >= 9999999999) {
            return false;
        }
        if (std::strlen(vCode) != 2) {
            return false;
        }
        if (std::strlen(sNumber) != 9) {
            return false;
        }
        return true;
    }


    void HealthCard::setEmpty() {
        delete[] m_name;
        m_name = nullptr;
    }

    void HealthCard::allocateAndCopy(const char* name) {
        delete[] m_name;
        m_name = new char[std::strlen(name) + 1];
        std::strcpy(m_name, name);
    }

    void HealthCard::extractChar(std::istream& istr, char ch) const {
        int next;
        next = istr.peek();
        if (next == ch) {
            istr.ignore();
        }
        else
        {
            istr.ignore(1000, ch);
            istr.setstate(std::ios::failbit);
        }
    }

    std::istream& HealthCard::read(std::istream& istr) {
        char name[MaxNameLength + 1];
        long long number;
        char vCode[3];
        char sNumber[10];

        number = 0;
        istr.getline(name, MaxNameLength, ',');
        if(!istr.fail()){
            istr >> number;
        }
        if(!istr.fail()){
            extractChar(istr, '-');
        }
        if(!istr.fail()){
            istr.get(vCode, 3, ',');
        }
        if(!istr.fail()){
            extractChar(istr, ',');
        }
        istr >> sNumber;
        if (!istr.fail()) {
            set(name, number, vCode, sNumber);
            istr.clear();
            istr.ignore(1000, '\n');
        } else{
            istr.clear();
            istr.ignore(1000, '\n');
        }
        return istr;
    }

    std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc) {
        return hc.print(ostr, false);
    }

    std::istream& operator>>(std::istream& istr, HealthCard& hc) {
        return hc.read(istr);
    }

}
