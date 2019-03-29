#ifndef STATE_H
#define STATE_H

using namespace std;

#include <vector>

class State {
    private:
        int board[3][3];
        State *parent;
        int grade;

        void initState();
        void swap(int *a, int *b);
        bool findNum(int& x, int& y, const int& num) const;
    public:
        State();

        int getGrade() const { return grade; }
        State *getParent() const {return parent; }

        void setFinalState();
        void setDefaultInitialState();
        void setRandomInitialState();
        int setManhattan();

        int getInvCount(int *arr) const;
        bool isSolvable() const;

        bool moveUp(const int& i, const int& j, State& child);
        bool moveRight(const int& i, const int& j, State& child);
        bool moveDown(const int& i, const int& j, State& child);
        bool moveLeft(const int& i, const int& j, State& child);

        void expand(vector<State>& children);
        
        void show() const;
        
        unsigned long long int getSum() const;

        friend bool operator==(const State& lhs, const State& rhs);
        friend bool operator!=(const State& lhs, const State& rhs);
        friend bool operator<(const State& lhs, const State& rhs);
        friend bool operator>(const State& lhs, const State& rhs);
        friend bool operator<=(const State& lhs, const State& rhs);
        friend bool operator>=(const State& lhs, const State& rhs);
};

#endif // STATE_H