#include <chrono>
#include <iostream>

namespace chr = std::chrono;
using namespace std;

class Timer
{
 private:
  chr::high_resolution_clock::time_point start;

 public:
  Timer() { start = chr::high_resolution_clock::now(); }

  ~Timer()
  {
    auto end = chr::high_resolution_clock::now();
    auto dur = chr::duration_cast<chr::seconds>(end - start);
    cout << "\n---------------------------------" << endl;
    cout << "Time taken: " << dur.count() << " [sec]" << endl;
    cout << "Press any key to continue . . . ";
    cin.ignore();
    cin.get();
  }
};

int GCD(int x, int y);
int gcd(int x, int y);
void pause(clock_t start);

int main(int argc, char const* argv[])
{
  string userInput;
  int x = 0, y = 0;
  Timer myClock;

  switch (argc) {
    case 1:
      do {
        cout << "Enter first integer: ";
        cin >> userInput;
        try {
          x = stoi(userInput);
        } catch (const out_of_range& oor) {
          cerr << "The number is outside the limits." << '\n';
        } catch (const invalid_argument& ia) {
          cerr << "The input is not an integer." << '\n';
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
          cerr << "The input is not an integer." << '\n';
        }
      } while (y == 0);

      cout << "\n-----\n";
      cout << "The gcd of " << x << " and " << y << " is: " << GCD(x, y)
           << endl;
      cout << "-----\n";

      //   pause(start);
      return 0;

    case 3: try { x = stoi(argv[1]);
      } catch (const out_of_range& oor) {
        cerr << "The first argument is outside the limits." << '\n';
        return 1;
      } catch (const invalid_argument& ia) {
        cerr << "The first argument is not an integer." << '\n';
        return 1;
      }
      try {
        y = stoi(argv[2]);
      } catch (const out_of_range& oor) {
        cerr << "The second argument is outside the limits." << '\n';
        return 1;
      } catch (const invalid_argument& ia) {
        cerr << "The second argument is not an integer." << '\n';
        return 1;
      }

      cout << "\n-----\n";
      cout << "The gcd of " << x << " and " << y << " is: " << GCD(x, y)
           << endl;
      cout << "-----\n";
      return 0;

    default: cout << "Wrong number of arguments." << endl; return 1;
  }
}

// Inserts the bigger number as the first argument in the gcd function.
int GCD(int x, int y) { return (x > y) ? gcd(x, y) : gcd(y, x); }

int gcd(int x, int y) { return y == 0 ? x : gcd(y, (x % y)); }