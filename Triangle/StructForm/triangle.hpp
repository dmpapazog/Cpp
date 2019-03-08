#ifndef TRIANGLE_H
#define TRIANGLE_H

struct Point {
    float x;
    float y;
};

class Triangle {
private:
    Point points[3];
public:
    // Create a triangle with every coordinate set to 0.
    Triangle();

    // Create a triangle given 3 seperate points.
    Triangle(const Point& A, const Point& B, const Point& C);

    Triangle(float A_x, float A_y,
             float B_x, float B_y,
             float C_x, float C_y);
    
    Point getPoint(int index);

    void setPoint(const Point& point, int index);
    void setXCoordinate(int index, float x);
    void setYCoordinate(int index, float y);

    float getXCoordinate(int index);
    float getYCoordinate(int index);

    double side(int firstPointIndex,int secondPointIndex);
    double corner(int index);
    double baseSide();
    double height();
    double area();

    bool isEquillateral();
    bool isIsosceles();
    bool isScalene();
    bool isRight();
    bool isAmblygonal();
    bool isAcute_angled();

};

#endif // TRIANGLE_H