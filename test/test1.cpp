#include <iostream>

class MyClass {
 private:
    int a, b;
    static int global;

 public:
    MyClass()
    {
        this->a = 0;
        this->b = 0;
    }

    const int &GetA() const { return this->a; }
    // const int &GetA()       { return this->a; }

    const int &GetB() const { return this->b; }
    const int &GetB()       { return this->b; }

    void SetA(int x) { this->a = x; }

    void SetB(int x) { this->b = x; }

    static int GetGlobal();

    ~MyClass() {delete this;}
};

int getAFromObject(const MyClass &object)
{
    return object.GetA();
}

int main()
{
    MyClass objectA;
    objectA.SetA(1);
    objectA.SetB(2);

    // int b = objectA.GetA();
    

    int a      = getAFromObject(objectA);
    int global = MyClass::GetGlobal();

    std::cout << "The value a of objectA is: " << a      << std::endl;
    std::cout << "The static variable is: "    << global << std::endl;

    return 0;
}

int MyClass::GetGlobal()
{
    return MyClass::global;
}

const int aFunction(int &a) {
    a  =   5;
    return 1;
}