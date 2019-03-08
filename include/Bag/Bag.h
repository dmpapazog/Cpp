#ifndef BAG_H
#define BAG_H

class Bag {
    protected:
        unsigned int *data, size;
        unsigned int N = 0; // the number of elements in the bag
    public:
        Bag();
        Bag(const Bag &old);
        Bag(int size);
        ~Bag();

        // returns 0 if the insertion was succesfull, 
        // returns 1 if the bag is full
        int insert(const unsigned int &element);
        int getSize() const;
        int getSum() const;

        // returns 0 if the element is not found, 
        // returns 1 otherwise
        int contains(const unsigned int &element) const;

};

#endif // BAG_H