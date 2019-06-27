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

int main(int argc, char const *argv[])
{
    ofstream outFile;
    outFile.open("..\\data\\integers.txt");

    if (outFile.is_open()) {
        size_t size = 10;
        int min = -100;
        int max =  1000;
        if (argc > 1) {
            size = stoull(argv[1]);
        }
        if (argc == 4) {
            min = stold(argv[2]);
            max = stold(argv[3]);
        }
        auto arr = new int[size];
        generate(arr, size, min, max);
        
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
        long double a = static_cast<long double>(rand()) / static_cast<long double>(RAND_MAX);
        arr[i] = a * static_cast<long double>((max - min)) + static_cast<long double>(min);
    }
}
