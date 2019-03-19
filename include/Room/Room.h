#ifndef ROOM_H
#define ROOM_H

class Room {
private:
    float length;
    float width;
    float height;
    double watts;
public:
    void  setLength(float length) { this->length = length;}
    float getLength()             { return this->length;  }

    void  setWidth(float width) { this->width = width;}
    float getWidth()            { return this->width; }

    void  setHeight(float height) { this->height = height;}
    float getHeight()             { return this->height;  }

    void   setWatts(double watts) { this->watts = watts;}
    double getWatts()             { return this->watts; }

    float  getArea();
    float  getVolume();
    double getWattsPerSqMeter();
    
};

#endif // ROOM_H