#include <iostream>

using namespace std;

class MyData {
    public:
        int i;
};

class Node {
    public:
        MyData data;
        Node *prev;
        Node *next;
};

class MyClass {
    private:
        Node *head;
    public:
        MyClass() {
            head = nullptr;
        }

        bool addData(const MyData &data) {
            Node *newNode = new Node();
            if (newNode == nullptr) {
                return false;
            }

            newNode->data = data;
            newNode->next = head;
            newNode->prev = nullptr;
            if (head != nullptr) {
                head->prev = newNode;
            }

            head = newNode;
            return true;
        }

        void printAll() {
            Node *temp = head;
            int i = 0;
            while (temp != nullptr) {
                cout << i + 1 << " element data: " << temp->data.i << endl;
                temp = temp->next;
                i++;
            }
        }
};



int main() {
    MyData *data1 = new MyData();
    MyClass obj1;

    data1->i = 1;
    obj1.addData(*data1);
    obj1.printAll();

    data1->i = 2;
    obj1.addData(*data1);
    obj1.printAll();

    data1->i = 3;
    obj1.printAll();

    delete data1;
    obj1.printAll();

    return 0;
}