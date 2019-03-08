#include <iostream>
#include <ctime>

using namespace std;

int GCD(int x, int y);
int gcd(int x, int y);
void pause(clock_t start);

int main(int argc, char const* argv[])
{
    clock_t start = clock();
    string userInput;
    int x = 0, y = 0;

    switch (argc) {
    case 1:
        do {
            cout << "Enter first integer: ";
            cin  >> userInput;
            try {
                x = stoi(userInput);
            } catch (const out_of_range& oor) {
                cerr << "The number is outside the limits." << '\n';
            } catch (const invalid_argument& ia) {
                cerr << "The input is not an integer."      << '\n';
            }
        } while (x == 0);

        do {
            cout << "Enter second integer: ";
            cin >> userInput;
            try {
                y = stoi(userInput);
            } catch (const out_of_range& oor) {
                cerr << "The number is outside the limits." << '\n';
            } catch (const invalid_argument& ia) {
                cerr << "The input is not an integer."      << '\n';
            }
        } while (y == 0);

        cout << "\n-----\n";
        cout << "The gcd of " << x << " and " << y << " is: " << GCD(x, y)
             << endl;
        cout << "-----\n";

        pause(start);
        return 0;

    case 3:
        try {
            x = stoi(argv[1]);
        } catch (const out_of_range& oor) {
            cerr << "The first argument is outside the limits." << '\n';
            pause(start);
            return 1;
        } catch (const invalid_argument& ia) {
            cerr << "The first argument is not an integer."     << '\n';
            pause(start);
            return 1;
        }
        try {
            y = stoi(argv[2]);
        } catch (const out_of_range& oor) {
            cerr << "The second argument is outside the limits." << '\n';
            pause(start);
            return 1;
        } catch (const invalid_argument& ia) {
            cerr << "The second argument is not an integer."     << '\n';
            pause(start);
            return 1;
        }

        cout << "\n-----\n";
        cout << "The gcd of " << x << " and " << y << " is: " << GCD(x, y)
             << endl;
        cout << "-----\n";             
        pause(start);
        return 0;

    default:
        cout << "Wrong number of arguments." << endl;
        pause(start);
        return 1;
    }
}


// Inserts the bigger number as the first argument in the gcd function.
int GCD(int x, int y)
{
    return (x > y) ? gcd(x, y) : gcd(y, x);
}

int gcd(int x, int y)
{
    if (y == 0) {
        return x;
    }
    return gcd(y, (x % y));
}

void pause(clock_t start)
{
    cout << "\n---------------------------------" << endl;
    cout << "Time taken: " << (clock() - start)/double(CLOCKS_PER_SEC) << " [seconds]" << endl;
    cout << "Press any key to continue . . . ";
    cin.ignore();
    cin.get();
}