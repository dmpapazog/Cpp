#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

class Triangle {
private:
    float A_x, A_y, B_x, B_y, C_x, C_y;

public:
    Triangle();
    Triangle(float A_x, float A_y,
             float B_x, float B_y,
             float C_x, float C_y);
             
    void setA_x(float A_x) { this->A_x = A_x; }
    void setA_y(float A_y) { this->A_y = A_y; }

    void setB_x(float B_x) { this->B_x = B_x; }
    void setB_y(float B_y) { this->B_y = B_y; }

    void setC_x(float C_x) { this->C_x = C_x; }
    void setC_y(float C_y) { this->C_y = C_y; }

    
    float getA_x() { return this->A_x; }
    float getA_y() { return this->A_y; }

    float getB_x() { return this->B_x; }
    float getB_y() { return this->B_y; }

    float getC_x() { return this->C_x; }
    float getC_y() { return this->C_y; }

    double sideA_B();
    double sideB_C();
    double sideC_A();

    double cornerA();
    double cornerB();
    double cornerC();

    bool isEquillateral();
    bool isIsosceles();
    bool isScalene();
    bool isRight();
    bool isAmblygonal();
    bool isAcute_angled();

    double baseSide();
    double height();
    double area();


    
};

#endif // TRIANGLE_HPP