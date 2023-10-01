#ifndef LAB_TRAIN_H
#define LAB_TRAIN_H

namespace sdds{
    const int MIN_TIME = 700;
    const int MAX_TIME = 2300;
    const int MAX_NO_OF_PASSENGERS = 1000;

    class Train {
        char *name;
        int numPassengers;
        int departureTime;

    public:
        void initialize();

        bool validTime(int value) const;

        bool validNoOfPassengers(int value) const;

        void set(const char *name);

        void set(int noOfPassengers, int departure);

        void set(const char *name, int noOfPassengers, int departure);

        void finalize();

        bool isInvalid() const;

        int noOfPassengers() const;

        const char *getName() const;

        int getDepartureTime() const;

        void display() const;

        bool load(int& leftBehind);

        bool updateDepartureTime();

        bool transfer(const Train& otherTrain);

        ~Train();
    };

}


#endif //LAB_TRAIN_H
