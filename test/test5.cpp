#include <iostream>
#include <map>

using namespace std;

struct Point {
    float x;
    float y;
};

int main()
{
    map<char, Point> myArray;

    float x = 1;
    float y = 1;

    for (char ch = 'A'; ch <= 'C'; ch++) {
        // Point temp{x, y};
        // myArray.insert(pair<char, Point> (ch, temp));
        
        myArray[ch] = {x, y};

        ++x;
        ++y;
    }

    for (const map<char, Point>::value_type& it : myArray) {
        const char     ch = it.first;
        const Point &temp = it.second;
        
        cout << ch     << endl;
        cout << temp.x << " and " << temp.y << endl << endl;
    }

    return 0;
}