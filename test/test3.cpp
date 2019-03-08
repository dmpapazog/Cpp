#include <iostream>
#include <limits>

bool byReference(int &a);

int main()
{
    int myValue = 8;
    if (byReference(myValue))
        std::cout << "The value of a is: " << myValue << std::endl;

    int myAge, myHeight;

    std::cout << "Enter your age: ";
    std::cin >> myAge;
    std::cout << "You are " << myAge << " years old.\n";
    std::cout << "Enter your height: ";
    std::cin >> myHeight;
    std::cout << "You are " << myHeight << " cms tall." << std::endl;

    unsigned short int a = std::numeric_limits<unsigned short int>::max();
    std::cout << "The max int value is " << a << std::endl;

    // std::cout << "\n\nPress any key to conintue... ";
    // fflush(stdin);
    // getchar();

    return 0;
}

bool byReference(int &a) {
    a += 2;
    return true;
}