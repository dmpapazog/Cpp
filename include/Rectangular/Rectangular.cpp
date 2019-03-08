#include "Rectangular.h"

Rectangular::Rectangular(float width, float height) {
    this->width = width;
    this->height = height;
}

float Rectangular::getArea() {
    return width * height;
}

float Rectangular::getPerimeter() {
    return (2 * width) + (2 * height);
}
