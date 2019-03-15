#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

class MyData {
    public:
        int a;
        char* name;
        void output() const {
            std::cout << a << ", " << name << std::endl;
        }
};

class Node {
    public:
        MyData data;
        Node *next;
        Node *prev;
};

class LinkedList {
    private:
        Node *head;
    public:
        LinkedList();
        ~LinkedList();
        bool addData(const MyData &data);
        Node *findData(const int &key) const;

        bool deleteNode(Node *node);
        bool printNode(const Node *const node) const;
        void printAll() const;
        Node *findMax() const;
        Node *findMin() const;
        bool update(Node *const node, const MyData &data);

        bool isEmpty();
};


#endif // LINKEDLIST_H