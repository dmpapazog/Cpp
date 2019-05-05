#include <iostream>
#include <cstdlib>
#include <memory>
#include <utility>

using namespace std;

template<class T>
class Dummy {
    private:
        unique_ptr<T> data;

    public:
        Dummy();
        Dummy(T data_)
            : data(make_unique<T>(data_))
        {
            cout << "\nConstructing with: " << *data << endl;
        }

        T getData() const {
            return *data;
        }

        void printAddress() const {
            cout << "Data is stored in: " << data.get() << '\n';
        }

        // Copy constructor
        Dummy(const Dummy<T>& that)
            : data(make_unique<T>(*that.data))
        {
            cout << "\nCopy constructor: " << *data << endl;
        }

        // Move constructor
        Dummy(Dummy&& that)
            : data(move(that.data))
        {
            cout << "\nMove constructor: " << *data << endl;
        }

        ~Dummy()
        {
            cout << "\nDestructing object in memory: " << data.get() << endl;
        }

};

void printShared(shared_ptr<int[]>& ptr, int size)
{
    cout << "\n ";
    for (int i = 0; i < size; i++) {
        cout << ptr[i] << ' ';
    }
}

void fillShared(shared_ptr<int[]>& ptr, int size)
{
    for (int i = 0; i < size; i++) {
        ptr[i] = i;
    }
}

int main()
{
    Dummy<int> a(5);
    Dummy<int> b(a);
    Dummy<int> c(move(a));
    // cout << "a holds: " << a.getData() << endl;
    cout << "b holds: " << b.getData() << endl;
    cout << "c holds: " << c.getData() << endl;
    b.printAddress();
    c.printAddress();
    a.printAddress();
    
    auto asd1 = make_shared<int[]>(10);
    fillShared(asd1, 10);
    printShared(asd1, 10);
    
    auto asd2 = asd1;
    printShared(asd1, 10);
    
    return EXIT_SUCCESS;
}
