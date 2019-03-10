#include <iostream>
#include "Set.h"

int Set::insert(const unsigned int& element)
{
    if (contains(element)) {
        return 1;
    }
    return Bag::insert(element);
}

Set Set::operator+(const unsigned int& element)
{
    Set c = *this;
    c.insert(element);
    return c;
}

void Set::operator=(const Set& b)
{
    int sixe = b.getSize();
    for (int i = 0; i < size; i++) {
        if (this->insert(b.data[i]) == 1) {
        };
    }
}

void Set::print() const
{
    int size = getSize();
    for (int i = 0; i < size; i++) {
        std::cout << "Element " << i << ": " << data[i] << std::endl;
    }
}