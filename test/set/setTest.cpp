#include <iostream>
#include <iomanip>
#include <set>

using namespace std;

class Dummy {
    private:
        int num;
        char name;
        int width;
        int *board;
    public:
        Dummy() { 
            num = 0; 
            name = 'a';
            width = 0;
            board = nullptr;
        }

        Dummy(int width) {
            this->width = width;
            board = new int[width * width];

            for (int i = 0; i < width; i++) {
                for (int j = 0; j < width; j++) {
                    board[i + j * width] = -1;
                }
            }
            num = 0; 
            name = 'a';
        }

        char getName() const { return name; }
        int getNum() const { return num; }
        int getTile(int x, int y) const { return board[x + y * width]; }
        
        void setNum(int num) { this->num = num; }
        void setName(char name) { this->name = name; }
        void setTile(int x, int y, int num) { board[x + y * width] = num;}

        friend ostream &operator<<(ostream& out, const Dummy& rhs);
        friend bool operator<(const Dummy& lhs, const Dummy& rhs);
        friend bool operator==(const Dummy& lhs, const Dummy& rhs);
        friend bool operator!=(const Dummy& lhs, const Dummy& rhs);
};

bool operator<(const Dummy& lhs, const Dummy& rhs) {
    return lhs.getNum() <= rhs.getNum();
}

bool operator==(const Dummy& lhs, const Dummy& rhs) {
    if ((lhs.num == rhs.num) && (lhs.name == rhs.name) && (lhs.width == rhs.width)) {
        for (int i = 0; i < lhs.width; i++) {
            for (int j = 0; j < lhs.width; j++) {
                if (lhs.board[i + j * lhs.width] != rhs.board[i + j * rhs.width]) {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

bool operator!=(const Dummy& lhs, const Dummy& rhs)
{
    return !operator==(lhs, rhs);
}

ostream &operator<<(ostream& out, const Dummy& rhs)
{
    out << rhs.num << '\n' 
        << rhs.name << '\n';
    for (int i = 0; i < rhs.width; i++) {
        for (int j = 0; j < rhs.width; j++) {
            out << "| " << setw(2) << rhs.board[i + j * rhs.width] << ' ';
        }
        out << "|\n";
    }
    return out;
}

int main()
{
    set<Dummy> mySet;
    int width = 5;
    Dummy myDummy(width);
    cout << myDummy;

    for (int i = 0, temp = 'a', counter = 0; i < width; i++) {
        for (int j = 0; j < width; j++, temp++, counter++) {
            myDummy.setNum(i);
            myDummy.setName(temp);
            myDummy.setTile(i, j, counter);
            mySet.insert(myDummy);
        }
    }

    for (size_t i = 0; !mySet.empty(); i++) {
        cout << i << ": "
             << *mySet.begin();
        mySet.erase(mySet.begin());
    }
    
    return 0;
}