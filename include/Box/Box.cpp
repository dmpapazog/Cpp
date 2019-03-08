#include "Box.h"

Box::Box(float width, float height, float length)
    : Rectangular(width, height)
{
    this->length = length;
}

double Box::getVolume() {
    return getWidth() * getHeight() * length;
}

double Box::getArea() {
    return (2 * (getWidth() * getHeight()) ) +
           (2 * (getWidth() * length) ) +
           (2 * (length * getHeight()) );
}

void Box::scale(double f) {
    setWidth(getWidth() * f);
    setHeight(getHeight() * f);
    length *= f;
}