#ifndef STATE_H
#define STATE_H

using namespace std;

#include <vector>
#include <string>

class DState {
    private:
        int side;
        int *board;
        DState *parent;
        int grade;
        string move;

        int getIndex(const int& x, const int& y) const;
        void initDState();
        void swap(int& a, int& b);
        bool findNum(int& x, int& y, const int& num) const;
    public:
        DState(const int& side);
        DState(const DState& old);
        ~DState();

        int getGrade() const { return grade; }
        DState *getParent() const {return parent; }
        string getMove() const { return move; }
        

        void setFinalDState();
        void setDefaultInitialDState();
        void setRandomInitialDState();
        int setManhattan();
        
        bool isSolvable() const;

        bool moveUp(const int& x, const int& y, DState& child);
        bool moveRight(const int& x, const int& y, DState& child);
        bool moveDown(const int& x, const int& y, DState& child);
        bool moveLeft(const int& x, const int& y, DState& child);

        void expand(vector<DState>& children);
        
        void show() const;
        
        string myHash() const;

        DState operator=(const DState& rhs);

        friend bool operator==(const DState& lhs, const DState& rhs);
        friend bool operator!=(const DState& lhs, const DState& rhs);
        friend bool operator<(const DState& lhs, const DState& rhs);
        friend bool operator>(const DState& lhs, const DState& rhs);
        friend bool operator<=(const DState& lhs, const DState& rhs);
        friend bool operator>=(const DState& lhs, const DState& rhs);
};

#endif // STATE_H