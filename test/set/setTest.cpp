#include <iostream>
#include <set>

using namespace std;

class Dummy {
    private:
        int num;
        char name;
    public:
        Dummy() { num = 0; name = 'a';}
        Dummy(int num, char name) { this->num = num; this->name = name; }

        void setNum(int num) { this->num = num; }
        int getNum() const { return num; }
        
        void setName(char name) { this->name = name; }
        char getName() const { return name; }

        friend bool operator<(const Dummy& lhs, const Dummy& rhs);
        friend bool operator==(const Dummy& lhs, const Dummy& rhs);
};

bool operator<(const Dummy& lhs, const Dummy& rhs) {
    return lhs.getNum() <= rhs.getNum();
}

bool operator==(const Dummy& lhs, const Dummy& rhs) {
    return (lhs.getNum() == rhs.getNum()) && (lhs.getName() == rhs.getName());
}

int main()
{
    set<Dummy> mySet;
    Dummy myDummy;
    for (int i = 0, temp = 'a'; i < 10; i++, temp++) {
        myDummy.setNum(i);
        myDummy.setName(temp);
        mySet.insert(myDummy);
    }

    myDummy.setNum(0);
    myDummy.setName('c');
    mySet.insert(myDummy);

    for (size_t i = 0; !mySet.empty(); i++) {
        cout << i << ": " << mySet.begin()->getNum() << ' ' << mySet.begin()->getName() << '\n';
        mySet.erase(mySet.begin());
    }
    
    return 0;
}