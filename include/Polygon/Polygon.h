#ifndef POLYGON_H
#define POLYGON_H

class Polygon {
    protected:
        unsigned int size;
        double *sides;
    public:
        Polygon();
        Polygon(const int &size, ...);

        double getLength();
        void setPolygon(const int &size, ...);
        double getEdge(const int& edge);

};


#endif // POLYGON_H