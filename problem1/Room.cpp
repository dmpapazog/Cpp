#include "Room.h"

float Room::getArea() {
    return this->width * this->length;
}

float Room::getVolume() {
    return this->getArea() * this->height;
}

double Room::getWattsPerSqMeter() {
    return this->watts / this->getArea();
}
