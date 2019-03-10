#include <iostream>
#include "MagneticDisk.h"

using namespace std;

MagneticDisk::MagneticDisk(char_c *description, Status_c &write, int_c &capacity, int_c &data)
: Disk(description, write)
{
    this->capacity = capacity;
    this->data = data;
}

void MagneticDisk::show() {
    Disk::show();
    cout << "\nFree space: " << capacity - data << " [MB]";
}