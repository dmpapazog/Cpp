#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
T mySumCalculator(const vector<T> &myVector);

int main()
{
    vector<int> myVector;
    myVector.push_back(1);
    myVector.shrink_to_fit();
    auto vectorSize = myVector.size();
    cout << "The vector has " << vectorSize << " elements."     << endl;
    cout << "The byte size of myVector is " << sizeof(myVector) << endl;

    vector<string> myWords;
    string         myString = "This is a string.";

    stringstream ss(myString);
    string       individualString;
    char         separator = ' ';

    while (getline(ss, individualString, separator)) {
        myWords.push_back(individualString);
    }

    for (size_t i = 0; i < myWords.size(); i++)
        cout << i << "st element of myWords vector is: " << myWords[i] << endl;

    vector<double> myFloats = {1.1, 1.2, 1.3, 1.4};

    double sum = mySumCalculator(myFloats);
    cout << "\nThe sum of myFloats is " << sum << endl;

    return 0;
}

template <typename T>
T mySumCalculator(const vector<T> &myVector)
{
    T sum = 0;
    for (size_t i = 0; i < myVector.size(); i++) sum += myVector[i];
    return sum;
}