//
// Created by DILKI2001 on 9/28/2023.
//

#include <cstring>
#include <iostream>
#include "Train.h"
using namespace std;

namespace sdds{
    void Train::initialize() {
        name = nullptr;
        numPassengers = -1;
        departureTime = -1;
    }

    bool Train::validTime(int value) const {
        return (MIN_TIME <= value && value <= MAX_TIME && (value % 100) <= 59);
    }

    bool Train::validNoOfPassengers(int value) const {
        return (value > 0 && value < MAX_NO_OF_PASSENGERS);
    }

    void Train::set(const char *newName) {
        finalize();
        if (newName && *newName) {
            name = new char[strlen(newName) + 1];
            strcpy(name, newName);
        }
    }

    void Train::set(int noOfPassengers, int departure) {
        if (validNoOfPassengers(noOfPassengers) && validTime(departure)) {
            numPassengers = noOfPassengers;
            departureTime = departure;
        } else {
            initialize();
        }

    }

    void Train::set(const char *newName, int noOfPassengers, int departure) {
        set(newName);
        set(noOfPassengers, departure);
    }

    void Train::finalize() {
        delete[] name;
        initialize();
    }

    bool Train::isInvalid() const {
        return (name == nullptr || numPassengers == -1 || departureTime == -1);
    }

    int Train::noOfPassengers() const {
        return numPassengers;
    }

    const char *Train::getName() const {
        return name;
    }

    int Train::getDepartureTime() const {
        return departureTime;
    }

    void Train::display() const {
        if (!isInvalid()) {
            cout << "NAME OF THE TRAIN:    " << name << endl;
            cout << "NUMBER OF PASSENGERS: " << numPassengers << endl;
            cout << "DEPARTURE TIME:       " << departureTime << endl;
        } else {
            cout << "Train in an invalid State!" << endl ;
        }
    }

    Train::~Train() {
        finalize();
    }

}







