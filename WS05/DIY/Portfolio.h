#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_


#include <ostream>

namespace sdds {

   class Portfolio {
       double m_value = 0;
       char m_stock[16];
       char m_type;

   public:
       Portfolio();
       Portfolio(double value, const char *stock, char type);
       void emptyPortfolio();
       void dispPortfolio() const;
       operator double() const;
       operator const char*() const;
       operator char() const;
       operator bool() const;
       Portfolio& operator+=(double amount);
       Portfolio& operator-=(double amount);
       bool operator~() const;

       friend Portfolio& operator<<(Portfolio& left, Portfolio& right);
       friend Portfolio& operator>>(Portfolio& left, Portfolio& right);
       friend double operator+(const Portfolio& left, const Portfolio& right);
       friend double& operator+=(double& left, const Portfolio& right);

       std::basic_ostream<char> &display() const;
   };


}
#endif // SDDS_Portfolio_H_