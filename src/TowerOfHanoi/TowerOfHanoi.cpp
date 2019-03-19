#include <iostream>

using namespace std;

int N = 0;

void printMessage(const int& n, const char& from_rod, const char& to_rod)
{
    cout << "Step " << ++N << ": Move disk " << n << " from " << from_rod << " to " << to_rod << '\n';
}

void towerOfHanoi(const int& n, const char& from_rod, const char& to_rod, const char& aux_rod)
{
    // If there is one disk to be moved,
    // move it directryl to the to_rod
    if (n == 1) {
        printMessage(n, from_rod, to_rod);
        return;
    }
    // Move the n - 1 disks to the 
    // auxiliary rod.
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);

    // Move the nth rod to the destination.
    printMessage(n, from_rod, to_rod);

    // Move the remaining n - 1 rods from the
    // auxiliary rod to the destination.
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n;
    cout << "How many disks are there? ";
    cin >> n;
    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}