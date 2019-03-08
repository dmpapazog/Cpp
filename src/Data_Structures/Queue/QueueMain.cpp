#include "queue.h"
#include <iostream>

using namespace std;

void printMenu(const Queue& myQueue);
void printQueue(const Queue& myQueue);

int main()
{
    int size;
    int temp;
    cout << "Enter the size of the queue: ";
    cin >> size;
    Queue myQueue(size);

    int choice;
    while (1) {
        system("cls");
        printMenu(myQueue);
        cin >> choice;
        switch (choice) {
        case 0:
            cout << "GoodBye!" << endl;
            return 0;
        case 1:
            if (myQueue.isEmpty()) {
                cout << "\nThe queue is empty." << endl;
            } else {
                cout << "\nThe queue is not empty." << endl;
            }
            system("pause");
            break;
        case 2:
            if (myQueue.isFull()) {
                cout << "\nThe queue is full." << endl;
            } else {
                cout << "\nThe queue is not full." << endl;
            }
            system("pause");
            break;
        case 3:
            cout << "\nEnter the number to add: ";
            cin >> temp;
            if (myQueue.enqueue(temp)) {
                cout << "Enqueue was successful." << endl;
            } else {
                cout << "Unsuccessful enqueue. Queue is full!" << endl;
            }
            system("pause");
            break;
        case 4:
            if (myQueue.dequeue(&temp)) {
                cout << "\nDequeue returned: " << temp << endl;
            } else {
                cout << "\nUnsuccessful dequeue. Queue is empty!" << endl;
            }
            system("pause");
            break;
        case 5:
            if (myQueue.isEmpty()) {
                cout << "\nCan't print an empty queue." << endl;
            } else {
                printQueue(myQueue);
            }
            system("pause");
            break;
        default:
            cout << "\nWrong selection." << endl;
            system("pause");
            break;
        }
    }
}

void printMenu(const Queue& myQueue)
{
    cout << "Select one option  (size = " << myQueue.getSize() << ")" << endl;
    cout << "------------------------------" << endl;
    cout << "0 - Exit the program." << endl;
    cout << "1 - Is the queue empty?" << endl;
    cout << "2 - Is the queue full?" << endl;
    cout << "3 - Add to the queue." << endl;
    cout << "4 - Remove from the queue." << endl;
    cout << "5 - Print the queue." << endl;
    cout << "------------------------------" << endl;
    cout << "Your selection: ";
}

void printQueue(const Queue& myQueue)
{
    cout << "\n|  ";
    for (int i = myQueue.getHead(); i != myQueue.getTail(); i = myQueue.increment(i)) {
        cout << myQueue.getData(i) << " |  ";
    }
    cout << myQueue.getData(myQueue.getTail()) << " |" << endl;
}