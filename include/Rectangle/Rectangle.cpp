#include "Rectangle.h"

Rectangle::Rectangle(const double &length, const double &width)
    : Polygon(4, length, length, width, width)
{
};

double Rectangle::getArea() const
{
    return sides[0] * sides[2];
}