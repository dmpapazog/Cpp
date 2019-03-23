#include <iostream>
#include <stdio.h>


// Show number of steps allong the way.
int step = 0;

void printMessage(const int& n, const char& from_rod, const char& to_rod)
{
    printf("Step %-4d: Move disk %2d from %c to %c\n", ++step, n, from_rod, to_rod);
}

void towerOfHanoi(const int& n, const char& from_rod, const char& to_rod, const char& aux_rod)
{
    // If there is one disk to be moved,
    // move it directly to the destination.
    if (n == 1) {
        printMessage(n, from_rod, to_rod);
        return;
    }
    // Move the n - 1 disks to
    // the auxiliary rod.
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);

    // Move the nth rod to the destination.
    printMessage(n, from_rod, to_rod);

    // Move the remaining n - 1 rods from the
    // auxiliary rod to the destination.
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int disks;
    std::cout << "How many disks are there? ";
    std::cin >> disks;
    towerOfHanoi(disks, 'A', 'C', 'B');

    return 0;
}