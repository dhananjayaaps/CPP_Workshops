#include <cstring>
#include <iomanip>
#include <iostream>
#include "CarInventory.h"

using namespace std;

namespace sdds{

    CarInventory::CarInventory() {
        m_type = nullptr;
        m_brand = nullptr;
        m_model = nullptr;
        resetInfo();
    }

    CarInventory::CarInventory(const char *type, const char *brand, const char *model, int year, int code, double price) {
        m_type = nullptr;
        m_brand = nullptr;
        m_model = nullptr;
        resetInfo();
        setInfo(type, brand, model, year, code, price);
    }

    CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price){

        if (type){
            m_type = new char[strlen(type)];
        }
        if (brand){
            m_brand = new char[strlen(brand)];
        }
        if (model){
            m_model = new char[strlen(model)];
        }
        strcpy(m_type, type);
        strcpy(m_brand, brand);
        strcpy(m_model, model);

        m_year = year;
        m_price = price;
        m_code = code;

        return *this;
    }

    void CarInventory::resetInfo() {
        delete[] m_type;
        delete[] m_brand;
        delete[] m_model;
        m_type = nullptr;
        m_brand = nullptr;
        m_model = nullptr;
        m_year = 0;
        m_code = 0;
        m_price = 0.0;
    }

    void CarInventory::printInfo() const {
        if (isValid()) {
            cout << "| " << left << setw(10) << m_type << " | " << setw(16) << m_brand << " | "
                << setw(16) << m_model << " | " << setw(4) << m_year << " | " << setw(4) << m_code
                << " | " << setw(9) << right << fixed << setprecision(2) << m_price << " |" << endl;
        }
    }

    bool CarInventory::isValid() const {
        return (m_type && m_brand && m_model && m_year >= 1990 && m_code >= 100 && m_code <= 999 && m_price > 0);
    }

    bool CarInventory::isSimilarTo(const CarInventory &car) const {
        if (isValid() && car.isValid()){
            return (strcmp(m_type, car.m_type) == 0 &&
                    strcmp(m_brand, car.m_brand) == 0 &&
                    strcmp(m_model, car.m_model) == 0 &&
                    m_year == car.m_year);
        }
        return false;
    }

    CarInventory::~CarInventory() {
        resetInfo();
    }

    int find_similar(CarInventory *car, const int num_cars) {
        for (int i = 0; i < num_cars; i++) {
            for (int j = i + 1; j < num_cars; j++) {
                if (car[i].isSimilarTo(car[j])) {
                    return i;
                }
            }
        }
        return -1;
    }

}

