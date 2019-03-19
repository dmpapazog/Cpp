#include <cmath>
#include "Triangle.h"

Triangle::Triangle() {
    setA_x(0);  setA_y(0);
    setB_x(0);  setB_y(0);
    setC_x(0);  setC_y(0);
}

Triangle::Triangle(float A_x, float A_y,
                   float B_x, float B_y,
                   float C_x, float C_y) {

    setA_x(A_x);    setA_y(A_y);
    setB_x(B_x);    setB_y(B_y);
    setC_x(C_x);    setC_y(C_y);
}

double Triangle::sideA_B() {
    return sqrt(pow(this->getA_x() - this->getB_x(),2) + pow(this->getA_y() - this->getB_y(),2));
}

double Triangle::sideB_C() {
    return sqrt(pow(this->getB_x() - this->getC_x(),2) + pow(this->getB_y() - this->getC_y(),2));
}

double Triangle::sideC_A() {
    return sqrt(pow(this->getC_x() - this->getA_x(),2) + pow(this->getC_y() - this->getA_y(),2));
}

double Triangle::cornerA() {
    return acos((pow(this->sideC_A(),2) + pow(this->sideA_B(),2) - pow(this->sideB_C(),2)) / (2 * this->sideC_A() * this->sideA_B()));
}

double Triangle::cornerB() {
    return acos((pow(this->sideA_B(),2) + pow(this->sideB_C(),2) - pow(this->sideC_A(),2)) / (2 * this->sideA_B() * this->sideB_C()));
}

double Triangle::cornerC() {
    return acos((pow(this->sideB_C(),2) + pow(this->sideC_A(),2) - pow(this->sideA_B(),2)) / (2 * this->sideB_C() * this->sideC_A()));
}

bool Triangle::isEquillateral() {
    return (this->sideA_B() == this->sideB_C()) == this->sideC_A();
}

bool Triangle::isIsosceles() {
    return this->sideA_B() == this->sideB_C() ||
           this->sideB_C() == this->sideC_A() ||
           this->sideC_A() == this->sideA_B();
}

bool Triangle::isScalene() {
    return !this->isIsosceles();
}

bool Triangle::isRight() {
    return (sin(this->cornerA()) == 1) ||
           (sin(this->cornerB()) == 1) ||
           (sin(this->cornerC()) == 1);
}

bool Triangle::isAmblygonal() {
    return (cos(this->cornerA()) < 0) ||
           (cos(this->cornerB()) < 0) ||
           (cos(this->cornerC()) < 0);
}

bool Triangle::isAcute_angled() {
    return !this->isAmblygonal();
}

double Triangle::baseSide() {
    return this->sideA_B();
}

double Triangle::height() {
    return sin(this->cornerA()) * this->sideC_A();
}

double Triangle::area() {
    return (this->baseSide() * this->height()) / 2;
}