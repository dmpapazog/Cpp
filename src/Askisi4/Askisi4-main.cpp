#include <iostream>
#include "../../include/Disk/Disk.h"
#include "../../include/MagneticDisk/MagneticDisk.h"

using namespace std;

int main() {
    Disk disk1("DOS", protect);
    Disk *disk2 = new Disk("Empty", enabled);

    MagneticDisk *disk3 = new MagneticDisk("Fireball", enabled, 4000, 2750);
    
    disk1.slide();
    disk2->slide();

    disk1.show();
    cout << endl << endl;
    disk2->show();
    cout << endl << endl;
    disk3->show();

    delete disk2;
    delete disk3;
    return 0;
}