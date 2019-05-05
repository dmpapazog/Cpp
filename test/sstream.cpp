#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string start = "I am a starting string.";
    stringstream ss(start, ios_base::in);

    string a[5];
    ss >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];

    for (int i = 0; i < 5; i++) {
        cout << a[i] << endl;
    }
    
    return 0;
}