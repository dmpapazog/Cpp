#ifndef POLYGONTEMPLATE_H
#define POLYGONTEMPLATE_H


class Polygon {
    protected:
        unsigned int size;
        double *sides;

        void initSides(double *const destination, const double &value);

        template<typename... Targs>
        void initSides(double *const destination, const double &value, const Targs&... args);
    public:
        Polygon();

        Polygon(const Polygon &old);

        template<typename... Targs>
        Polygon(const int &size, const Targs&... args);


        template<typename... Targs>
        void setPolygon(const int &size, const Targs&... args);

        double getLength() const;

        double getEdge(const int& edge) const;

};

#include "Polygon-template.cpp"

#endif // POLYGONTEMPLATE_H