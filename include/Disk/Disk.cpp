#include <string.h>
#include <iostream>
#include "Disk.h"

using namespace std;

Disk::Disk() {
    description = new char[30];
    write = protect;
}

Disk::Disk(const char *description, const Status &write) {
    this->description = new char[30];
    strcpy(this->description, description);
    this->write = write;
}

void Disk::slide() {
    if (write) {
        write = protect;
    } else {
        write = enabled;
    }
}

void Disk::show() {
    cout << "\nDescription: " << description << endl;
    cout << "Writing status: ";
    if (write) {
        cout << "enabled";
    } else {
        cout << "protect";
    }
}