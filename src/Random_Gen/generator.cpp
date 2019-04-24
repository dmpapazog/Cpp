#include <random>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

// Save an array of size of random numbers
// of type T to arr from min to max.
template<typename T>
void generate(T* const arr, const size_t& size = 1000, const T& min = -10000, const T& max = 10000000);

int main()
{
    ofstream outFile;
    outFile.open("..\\data\\integers.txt");

    if (outFile.is_open()) {
        const size_t size = 1000000;
        auto arr = new long long[size];
        generate(arr, size);
        
        for (size_t i = 0; i < size; i++) {
            outFile << arr[i] << '\n';
        }

        outFile.close();
        return EXIT_SUCCESS;
    } else {
        return EXIT_FAILURE;
    }
}


template<typename T>
void generate(T* const arr, const size_t& size, const T& min, const T& max)
{
    srand(time(NULL));
    for (size_t i = 0; i < size; i++) {
        double a = double(rand()) / RAND_MAX;
        arr[i] = a * double((max - min)) + min;
    }
}
