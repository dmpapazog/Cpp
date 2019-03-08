#include <cmath>
#include "triangle.hpp"


Point Triangle::getPoint(int index) {
    return this->points[index];
}

void Triangle::setPoint(const Point& point, int index) {
    this->getPoint(index) = point;
}

void Triangle::setXCoordinate(int index, float x) {
    this->getPoint(index).x = x;
}

void Triangle::setYCoordinate(int index, float y) {
    this->getPoint(index).y = y;
}

float Triangle::getXCoordinate(int index) {
    return this->getPoint(index).x;
}

float Triangle::getYCoordinate(int index) {
    return this->getPoint(index).y;
}

Triangle::Triangle() {
    for (int i = 0; i < 3; i++) {
        this->setXCoordinate(i, 0);
        this->setYCoordinate(i, 0);
    }
}

Triangle::Triangle(const Point& A, const Point& B, const Point& C) {
    this->setPoint(A, 0);
    this->setPoint(B, 1);
    this->setPoint(C, 2);
}

Triangle::Triangle(float A_x, float A_y,
                   float B_x, float B_y,
                   float C_x, float C_y) {
    this->setXCoordinate(0, A_x);
    this->setYCoordinate(0, A_y);

    this->setXCoordinate(1, B_x);
    this->setYCoordinate(1, B_y);

    this->setXCoordinate(2, C_x);
    this->setYCoordinate(2, C_y);
}

double Triangle::side(int firstPointIndex, int secondPointIndex) {
    return sqrt(pow(this->getXCoordinate(firstPointIndex) - this->getXCoordinate(secondPointIndex),2) + pow(this->getYCoordinate(firstPointIndex) - this->getYCoordinate(secondPointIndex),2));
}

double Triangle::corner(int index) {
    int secondPoint = (index + 1) % 3;
    int thirdPoint = (secondPoint + 1) % 3;
    return acos((pow(this->side(index, thirdPoint),2) + pow(this->side(index, secondPoint),2) - pow(this->side(secondPoint, thirdPoint),2)) / (2 * this->side(index, thirdPoint) * this->side(index, secondPoint)));
}

double Triangle::baseSide() {
    double temp = this->side(0, 1);
    if (temp < this->side(1, 2)) {
        temp = this->side(1, 2);
    } else if ( temp < this->side(2, 0)) {
        temp = this->side(2, 0);
    }
    return temp;
}

double Triangle::height() {
    return acos(sin(this->corner(0)) * this->side(0, 2));
}

double Triangle::area() {
    return (this->baseSide() * this->height()) / 2;
}

bool Triangle::isEquillateral() {
    return (this->side(0, 1) == this->side(1, 2)) == this->side(2, 0);
}

bool Triangle::isIsosceles() {
    for (int i = 0; i < 3; i ++) {
        int j = (i + 1) % 3;
        int k = (j + 1) % 3;
        if (this->side(i, j) == this->side(j, k)) {
            return true;
        }
    }
    return false;
}

bool Triangle::isScalene() {
    return !this->isIsosceles();
}

bool Triangle::isRight() {
    
}