#ifndef RECTANGULAR_H
#define RECTANGULAR_H

class Rectangular {
    protected:
        float width, height;
    public:
        Rectangular() {};
        Rectangular(float width, float height);

        void   setWidth(float width)   { this->width  = width; }
        void   setHeight(float height) { this->height = height;}
        
        float getWidth()  { return width; }
        float getHeight() { return height;}

        float getArea();
        float getPerimeter();
};


#endif // RECTANGULAR_H