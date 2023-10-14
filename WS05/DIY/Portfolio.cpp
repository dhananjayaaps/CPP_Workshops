#define _CRT_SECURE_NO_WARNINGS

#include "Portfolio.h"
#include <iostream>
#include <cstring>

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
       emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }

    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && ( type == 'V' || type == 'G' || type == 'I') ) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const{
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Value: ";
            cout.width(10);
            cout << double(*this);
            cout << " | ";
            cout << " Type: ";
            cout << char(*this);
    }
    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }

    Portfolio::operator double() const {
        return m_value;
    }

    Portfolio::operator const char*() const {
        return m_stock;
    }

    Portfolio::operator char() const {
        return m_type;
    }

    Portfolio::operator bool() const {
        return (m_type == 'G' || m_type == 'V' || m_type == 'I');
    }

    Portfolio& Portfolio::operator+=(double amount) {
        if (*this && amount >= 0) {
            m_value += amount;
        }
        return *this;
    }

    Portfolio& Portfolio::operator-=(double amount) {
        if (*this && m_value - amount >= 0) {
            m_value -= amount;
        }
        return *this;
    }

    bool Portfolio::operator~() const {
        return (m_value < 0);
    }

    Portfolio &operator<<(Portfolio &left, Portfolio &right) {
        if (left && right) {
            left.m_value += right.m_value;
            right.emptyPortfolio();
        }
        return left;
    }

    Portfolio &operator>>(Portfolio &left, Portfolio &right) {
        if (left && right) {
            right.m_value += left.m_value;
            left.emptyPortfolio();
        }
        return left;
    }

    double operator+(const Portfolio &left, const Portfolio &right) {
        if (left && right) {
            return left.m_value + right.m_value;
        }
        return 0;
    }

    double& operator+=(double& left, const Portfolio& right) {
            left += right.m_value;
        return left;
    }

}