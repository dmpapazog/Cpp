#ifndef SET_H
#define SET_H

#include "../Bag/Bag.h"

using namespace std;

class Set : public Bag {
public:
    Set()
        : Bag(){};
    Set(int size)
        : Bag(size){};
    Set(const Set& old)
        : Bag(old){};

    // returns 0 if the insertion is successfull,
    // returns 1 otherwise
    int insert(const unsigned int& element);
    Set operator+(const unsigned int& element);
    void operator=(const Set& b);
    void print() const;
};

#endif // SET_H