#ifndef BOX_H
#define BOX_H

#include "../Rectangular/Rectangular.h"

class Box : public Rectangular {
    private:
        float length;
    public:
        Box(float width, float height, float length);
        
        double getVolume();
        double getArea();

        void scale(double f);
};

#endif // BOX_H