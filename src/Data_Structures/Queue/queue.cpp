#include <iostream>
#include "queue.h"

int Queue::increment(const int val) const
{
    return (val + 1) % size;
}

Queue::Queue()
{
    size = 10;
    head = -1;
    tail = -1;
    data = new int[size];
}

Queue::Queue(int size)
{
    this->size = size;
    head = -1;
    tail = -1;
    data = new int[this->size];
}

Queue::Queue(const Queue& old)
{
    this->size = old.size;
    this->head = old.head;
    this->tail = old.tail;
    this->data = new int[this->size];

    for (int i = head; i != tail; i = increment(i)) {
        this->data[i] = old.data[i];
    }
    this->data[tail] = old.data[tail];
}

Queue::~Queue()
{
    std::cout << "Deleting queue..." << std::endl;
    delete[] data;
    std::cout << "Queue deleted." << std::endl;
}

bool Queue::isEmpty()
{
    return (head == -1) && (tail == -1);
}

bool Queue::isFull()
{
    if (isEmpty()) {
        return false;
    }
    return increment(tail) == head;
}

bool Queue::enqueue(int elem)
{
    if (isFull()) {
        return false;
    } else {
        if (isEmpty()) {
            head++;
        }
        tail = increment(tail);
        data[tail] = elem;
        return true;
    }
}

bool Queue::dequeue(int* elem)
{
    if (isEmpty()) {
        return false;
    } else {
        *elem = data[head];
        if (head == tail) {
            head = -1;
            tail = -1;
        } else {
            head = increment(head);
        }
        return true;
    }
}

int Queue::getSize() const {
    return size;
}

int Queue::getData(int index) const {
    return data[index];
}

int Queue::getHead() const {
    return head;
}

int Queue::getTail() const {
    return tail;
}