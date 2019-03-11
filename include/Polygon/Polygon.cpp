#include <cstdarg>
#include "Polygon.h"

Polygon::Polygon() {
    size = 0;
}

Polygon::Polygon(const int &size, ...) {
    this->size = size;
    this->sides = new double[size];

    va_list args;
    va_start(args, size);
    for (int i = 0; i < size; i++) {
        double temp = va_arg(args, double);
        sides[i] = temp;
    }
    va_end(args);
}

double Polygon::getLength() {
    unsigned int mySize = size;
    double length = 0;
    for (int i = 0; i < mySize; i++) {
        length += sides[i];
    }
    return length;
}

void Polygon::setPolygon(const int& size, ...) {
    delete[] this->sides;
    this->size = size;
    this->sides = new double[size];

    va_list args;
    va_start(args, size);
    for (int i = 0; i < size; i++) {
        double temp = va_arg(args, double);
        sides[i] = temp;
    }
    va_end(args);
}

double Polygon::getEdge(const int& edge) {
    if (edge < size) {
        return sides[edge];
    } else {
        return -1;
    }
}