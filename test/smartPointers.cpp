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
    
    shared_ptr<int[]> asd1(new int[10], [] (int* i) { 
        delete[] i; 
    });
    fillShared(asd1, 10);
    printShared(asd1, 10);
    
    auto asd2 = asd1;
    printShared(asd1, 10);

    auto unique1 = make_unique<int>(5);
    unique_ptr<int> unique2(unique1.get());

    cout << "\nUnique1: " << *unique1;
    cout << "\nUnique2: " << *unique2;
    cout << "\nPointer of unique1: " << unique1.get();
    cout << "\nPointer of unique2: " << unique2.get();
    unique2.release();

    return EXIT_SUCCESS;
}
