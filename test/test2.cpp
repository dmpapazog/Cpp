#include <iostream>

int myFunctionByReference(const int &value);
int myFunctionByValue(int value);

int main()
{
    int a = 0;
    std::cout << "The address of 'a' in main is: \t\t" << &a << std::endl;
    std::cout << "Calling the function using the variable by reference." << std::endl;
    std::cout << "The incrimented value of a is: \t" << myFunctionByReference(a) << std::endl;
    std::cout << "Calling the function using the variable by value." << std::endl;
    std::cout << "The incrimented value of a is: \t" << myFunctionByValue(a) << std::endl;

    return 0;
}

int myFunctionByReference(const int &value)
{
    std::cout << "The address of 'a' in myFunction is: \t" << &value << std::endl;
    return [](const int &lamdaValue) {
        std::cout << "The address of 'a' in the lamda is: \t" << &lamdaValue << std::endl;
        return lamdaValue + 1;
    }(value);
}

int myFunctionByValue(int value)
{
    std::cout << "The address of 'a' in myFunction is: \t" << &value << std::endl;
    return [](int lamdaValue) {
        std::cout << "The address of 'a' in the lamda is: \t" << &lamdaValue << std::endl;
        return lamdaValue + 1;
    }(value);
}
