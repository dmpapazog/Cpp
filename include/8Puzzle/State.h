#ifndef STATE_H
#define STATE_H

#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

class State {
private:
    int** board;
    int size;
    State* parent;

    void swap(int* a, int* b);

public:
    State();
    State(int size);

    void setFinalState();
    void setRandomInitialState();
    void setDefaultInitialState();
    void setBoard(const int** board, int size);

    void printBoard() const;

    bool moveUp(int i, int j) const;
    bool moveRight(int i, int j) const;
    bool moveDown(int i, int j) const;
    bool moveLeft(int i, int j) const;

    void expand(queue<State>* frontier);
    void expand(stack<State> *frontier);

    bool operator==(const State& right) const;
    bool operator!=(const State& right) const;
    void operator=(const State& right);

    unsigned long long int getSum() const;

    int getInvCount(int* arr) const;
    bool isSolvable() const;

    State* getParent() const { return parent; }

    // bool operator<(const State &right) const;
};

namespace std {
template <>
struct hash<State> {
    size_t operator()(const State& k) const
    {
        // Compute individual hash based on getSum()
        return hash<unsigned long long int>()(k.getSum());
    }
};
}

#endif // STATE_H