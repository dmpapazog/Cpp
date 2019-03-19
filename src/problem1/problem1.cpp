/** Εφαρμοφή των κλάσεων με παράδειγμα
 * ένα δωμάτιο
 */

#include <iostream>
#include "include/Room/Room.h"

using namespace std;

int main()
{
    Room room;
    float temp;

    room.setWatts(2000);

    cout << "Enter the length, the width and height of the room\n";
    cin >> temp;
    room.setLength(temp);
    cin >> temp;
    room.setWidth(temp);
    cin >> temp;
    room.setHeight(temp);

    cout << "The area of the room is: "   << room.getArea()            << " m"     << endl;
    cout << "The volume of the room is: " << room.getVolume()          << " m^2"   << endl;
    cout << "Watts per square meter is: " << room.getWattsPerSqMeter() << " W/m^2" << endl;
    

    return 0;
}
