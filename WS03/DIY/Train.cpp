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
        delete [] name;

        if (newName && *newName) {
            name = new char[strlen(newName) + 1];
            strcpy(name, newName);
        }
    }

    void Train::set(int noOfPassengers, int departure) {
        if (validNoOfPassengers(noOfPassengers) && validTime(departure)) {
            numPassengers = noOfPassengers;
            departureTime = departure;
        }

    }

    void Train::set(const char *newName, int noOfPassengers, int departure) {
        set(newName);
        set(noOfPassengers, departure);
    }

    void Train::finalize() {
        delete [] name;
        name = nullptr;
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


    bool Train::load(int& leftBehind) {
        int passengersToBoard;
        cout << "Enter number of passengers boarding:" << endl << "> "
                                                                  "";
        cin >> passengersToBoard;

        if (passengersToBoard <= 0) {
            leftBehind = 0;
            return true;
        }

        if (passengersToBoard <= MAX_NO_OF_PASSENGERS - numPassengers) {
            numPassengers += passengersToBoard;
            leftBehind = 0;
            return true;
        } else {
            leftBehind = passengersToBoard - (MAX_NO_OF_PASSENGERS - numPassengers);
            numPassengers = MAX_NO_OF_PASSENGERS;
            return false;
        }
    }

    bool Train::updateDepartureTime() {
        int newDepartureTime;
        cout << "Enter new departure time:" << endl << "> ";
        cin >> newDepartureTime;

        if (validTime(newDepartureTime)) {
            departureTime = newDepartureTime;
            return true;
        } else {
            departureTime = -1;
            return false;
        }
    }

    bool Train::transfer(const Train& otherTrain) {
        if (isInvalid() || otherTrain.isInvalid()) {
            return false;
        }

        char* combinedName = new char[strlen(name) + strlen(otherTrain.name) + 3];
        strcpy(combinedName, name);
        strcat(combinedName, ", ");
        strcat(combinedName, otherTrain.name);

        int leftBehind;

        if (otherTrain.numPassengers <= MAX_NO_OF_PASSENGERS - numPassengers) {
            numPassengers += otherTrain.numPassengers;
        } else {
            leftBehind = otherTrain.numPassengers - (MAX_NO_OF_PASSENGERS - numPassengers);
            numPassengers = MAX_NO_OF_PASSENGERS;
            cout << "Train is full; " << leftBehind << " passengers of " << otherTrain.name << " could not be boarded!" << endl;
        }

        delete[] name;
        name = combinedName;

        return true;
    }

    Train::~Train() {
        finalize();
    }
}
