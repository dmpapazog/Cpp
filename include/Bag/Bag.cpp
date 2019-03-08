#include "Bag.h"

Bag::Bag() {
    size = 1;
    data = new unsigned int[size];
}

Bag::Bag(const Bag &old) {
    this->size = old.size;
    this->N = old.N;
    this->data = new unsigned int[this->size];
    for (int i = 0; i < this->N; i++) {
        this->data[i] = old.data[i];
    }
}

Bag::Bag(int size) {
    this->size = size;
    data = new unsigned int[size];
}

Bag::~Bag()
{
    delete[] data;
}

int Bag::insert(const unsigned int &element)
{
    if (N == size) {
        return 1;
    }
    data[N] = element;
    N++;
    return 0;
}

int Bag::getSize() const
{
    return N;
}

int Bag::getSum() const
{
    unsigned int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += data[i];
    }
    return sum;
}

int Bag::contains(const unsigned int &element) const
{
    for (int i = 0; i < N; i++) {
        if (data[i] == element) {
            return 1;
        }
    }
    return 0;
}