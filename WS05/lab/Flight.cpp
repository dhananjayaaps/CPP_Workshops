#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title, "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }

    Flight::Flight(int passengers, double fuel, const char *title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title, title);
        }
    }

    std::ostream &Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        } else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        } else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char *) (*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

    Flight::operator bool() const {
        return m_passengers > 0 && m_fuel >= m_passengers * 600;
    }

    Flight::operator int() const {
        return m_passengers;
    }

    Flight::operator double() const {
        return m_fuel;
    }

    Flight::operator const char *() const {
        return m_title;
    }

    bool Flight::operator~() const {
        return m_passengers == 0;;
    }

    Flight &Flight::operator=(Flight &other) {
        strcpy(m_title, other.m_title);
        m_fuel = other.m_fuel;
        m_passengers = other.m_passengers;
        other.emptyPlane();
        return *this;
    }

    Flight &Flight::operator=(int passengers) {
        if (passengers > 0 && passengers <= Boen747Capacity) {
            m_passengers = passengers;
        }
        return *this;
    }

    Flight &Flight::operator=(double fuel) {
        if (fuel >= 0 && fuel <= FuelTankCapacity) {
            m_fuel = fuel;
        }
        return *this;
    }

    Flight &Flight::operator+=(double fuel) {
        if (fuel >= 0 && m_fuel+fuel <= FuelTankCapacity) {
            m_fuel += fuel;
        } else if(fuel >= 0 && FuelTankCapacity-fuel > 0){
            m_fuel += FuelTankCapacity-fuel;
        }
        return *this;
    }

    Flight &Flight::operator+=(int passengers) {
        if (passengers >= 0 && m_passengers + passengers <= FuelTankCapacity) {
            m_passengers += passengers;
        } else if(passengers >= 0 && FuelTankCapacity-passengers > 0){
            m_passengers += FuelTankCapacity-passengers;
        }
        return *this;
    }

    Flight &Flight::operator-=(double fuel) {
        if(fuel > 0 && fuel <= m_fuel){
            m_fuel -= fuel;
        } else if(fuel > 0){
            m_fuel = 0;
        }
        return *this;
    }

    Flight &Flight::operator-=(int passengers) {
        if(passengers > 0 && passengers <= m_passengers){
            m_passengers -= passengers;
        } else if(passengers > 0){
            m_passengers = 0;
        }
        return *this;
    }

    Flight& Flight::operator<<(Flight& other) {
        if (this != &other && *this && other) {
            int totalPassengers = m_passengers + other.m_passengers;
            if (totalPassengers <= Boen747Capacity) {
                m_passengers = totalPassengers;
                other.m_passengers = 0;
            } else {
                m_passengers = Boen747Capacity;
                other.m_passengers = totalPassengers - Boen747Capacity;
            }
        }
        return *this;
    }

    Flight& Flight::operator>>(Flight& other) {
        other << *this;
        return *this;
    }

    int operator+=(int& passengers, const Flight& flight) {
        passengers += int(flight);
        return passengers;
    }

    int operator+(const Flight& left, const Flight& right) {
        return int(left) + int(right);
    }


}