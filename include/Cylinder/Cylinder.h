#ifndef CYLINDER_H
#define CYLINDER_H

#include "../Circle/Circle.h"

class Cylinder : public Circle {
    private:
        float radius, height;
    public:
        Cylinder(float height, float radius);
        double getVolume();
        void show();
};

#endif // CYLINDER_H