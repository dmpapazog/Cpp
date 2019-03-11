#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../Polygon/Polygon.h"

class Rectangle : public Polygon {
    public:
        Rectangle(const double &length, const double &width);
        
        double getArea() const;
};


#endif // RECTANGLE_H