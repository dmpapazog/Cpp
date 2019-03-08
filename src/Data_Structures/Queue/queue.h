#ifndef QUEUE_H
#define QUEUE_H

class Queue {
    private:
        int size;
        int head, tail;
        int *data;
    public:
        Queue();
        Queue(int size);
        Queue(const Queue &old);
        ~Queue();
        bool isEmpty();
        bool isFull();
        bool enqueue(int elem);
        bool dequeue(int *elem);
        
        int increment(const int val) const;
        
        // only for printing
        int getData(int index) const;
        int getSize() const;
        int getHead() const;
        int getTail() const;
        // only for printing

};

#endif // QUEUE_H