#ifndef POLYGONTEMPLATE_CPP
#define POLYGONTEMPLATE_CPP

#include "Polygon-template.h"

void Polygon::initSides(double *const destination, const double &value)
{
    *destination = value;
}

template <typename... Targs>
void Polygon::initSides(double *const destination, const double &value, const Targs &... args)
{
    *destination = value;
    initSides(destination + 1, args...);
}

template <typename... Targs>
Polygon::Polygon(const int &size, const Targs &... args)
{
    this->size = size;
    sides = new double[size];
    initSides(sides, args...);
}

Polygon::Polygon(const Polygon &old)
{
    this->size = old.size;
    this->sides = new double[this->size];
    for (int i = 0; i < this->size; i++) {
        this->sides[i] = old.sides[i];
    }
}

template <typename... Targs>
void Polygon::setPolygon(const int &size, const Targs &... args)
{
    delete[] sides;
    this->size = size;
    sides = new double[size];
    initSides(sides, args...);
}

double Polygon::getLength() const
{
    unsigned int mySize = size;
    double length = 0;
    for (int i = 0; i < mySize; i++)
    {
        length += sides[i];
    }
    return length;
}

double Polygon::getEdge(const int &edge) const
{
    if (edge < size)
    {
        return sides[edge];
    }
    else
    {
        return -1;
    }
}

#endif // POLYGONTEMPLATE_CPP