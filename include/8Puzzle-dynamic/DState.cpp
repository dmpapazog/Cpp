#include "DState.h"
#include <cstdlib>
#include <ctime>
#include <random>

#include <iostream>
#include <iomanip>

#include <iterator>
#include <set>

#include <climits>
#include <cmath>

using namespace std;

DState::DState(const int& side)
{
    this->side = side;
    board = new int[side * side];

    initDState();
    parent = nullptr;
    grade = INT32_MAX;
}

DState::DState(const DState& old)
{
    this->side = old.side;
    this->board = new int[this->side * this->side];

    for (int i = 0; i < this->side; i++) {
        for (int j = 0; j < this->side; j++) {
            this->board[i * this->side + j] = old.board[i * old.side + j];
        }
    }
    this->parent = old.parent;
    this->grade = old.grade;
    this->move = old.move;
}

DState::~DState()
{
    delete[] board;
}

DState DState::operator=(const DState& rhs)
{
    if (this->side == rhs.side) {
        for (int i = 0; i < this->side; i++) {
            for (int j = 0; j < this->side; j++) {
                this->board[i * this->side + j] = rhs.board[i * rhs.side + j];
            }
        }
        this->parent = rhs.parent;
        this->grade = rhs.grade;
        this->move = rhs.move;
    }

    return *this;
}

int DState::getIndex(const int& x, const int& y) const
{
    return x * side + y;
}

void DState::initDState()
{
    for (int i = 0; i < side; i++)
        for (int j = 0; j < side; j++)
            board[i * side + j] = -1;
}

void DState::show() const
{
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++)
            cout << "| " << setw(2) << board[i * side + j] << " ";
        cout << "|\n";
    }
}

void DState::swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

bool DState::findNum(int& x, int& y, const int& num) const
{
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            if (board[i * side + j] == num) {
                x = i;
                y = j;
                return true;
            }
        }
    }
    return false;
}

bool DState::moveUp(const int& x, const int& y, DState& child)
{
    if (x > 0) {
        int index0 = getIndex(x, y);
        int indexUp = getIndex(x - 1, y);
        child = *this;
        child.swap(child.board[indexUp], child.board[index0]);

        child.parent = this;
        child.grade = child.setManhattan();
        
        child.move = "UP";
        return true;
    }

    return false;
}

bool DState::moveRight(const int& x, const int& y, DState& child)
{
    if (y < side - 1) {
        int index0 = getIndex(x, y);
        int indexRight = getIndex(x, y + 1);
        child = *this;
        child.swap(child.board[indexRight], child.board[index0]);

        child.parent = this;
        child.grade = child.setManhattan();

        child.move = "RIGHT";
        return true;
    }

    return false;
}

bool DState::moveDown(const int& x, const int& y, DState& child)
{
    if (x < side - 1) {
        int index0 = getIndex(x, y);
        int indexDown = getIndex(x + 1, y);
        child = *this;
        child.swap(child.board[indexDown], child.board[index0]);

        child.parent = this;
        child.grade = child.setManhattan();

        child.move = "DOWN";
        return true;
    }

    return false;
}

bool DState::moveLeft(const int& x, const int& y, DState& child)
{
    if (y > 0) {
        int index0 = getIndex(x, y);
        int indexLeft = getIndex(x, y - 1);
        child = *this;
        child.swap(child.board[indexLeft], child.board[index0]);

        child.parent = this;
        child.grade = child.setManhattan();

        child.move = "LEFT";
        return true;
    }

    return false;
}

bool operator==(const DState& lhs, const DState& rhs)
{
    if ((lhs.grade == rhs.grade) && (lhs.side == rhs.side)) {
        for (int i = 0; i < lhs.side; i++) {
            for (int j = 0; j < lhs.side; j++) {
                if (lhs.board[i * lhs.side + j] != rhs.board[i * rhs.side + j]) {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

bool operator!=(const DState& lhs, const DState& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const DState& lhs, const DState& rhs)
{
    return (lhs.grade < rhs.grade);
}

bool operator>(const DState& lhs, const DState& rhs)
{
    return rhs < lhs;
}

bool operator<=(const DState& lhs, const DState& rhs)
{
    return (lhs < rhs) || (lhs == rhs);
}
bool operator>=(const DState& lhs, const DState& rhs)
{
    return (lhs > rhs) || (lhs == rhs);
}

void DState::setFinalDState()
{
    int count = 1;
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            board[i * side + j] = count++ % (side * side);
        }
    }

    grade = 0;
}

void DState::setDefaultInitialDState()
{
    board[0] = 6; board[1] = 7; board[2] = 1;
    board[3] = 0; board[4] = 3; board[5] = 2;
    board[6] = 8; board[7] = 5; board[8] = 4;
    
    parent = nullptr;
    grade = setManhattan();
}

void DState::setRandomInitialDState()
{
    srand(time(NULL));

    set<int> NUMBERS;
    for (int i = 0; i < (side * side); i++) {
        NUMBERS.insert(i);
    }

    int randPosition;
    set<int>::iterator it;
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            it = NUMBERS.begin();
            randPosition = rand() % NUMBERS.size();
            advance(it, randPosition);
            board[i * side + j] = *it;
            NUMBERS.erase(it);
        }
    }

    parent = nullptr;
    grade = setManhattan();
}

int DState::setManhattan()
{
    DState finalState(this->side);
    finalState.setFinalDState();
    int temp = 0;

    int indexF_i, indexF_j, index_i, index_j;

    for (int num = 0; num < (this->side * this->side); num++) {
        finalState.findNum(indexF_i, indexF_j, num);
        this->findNum(index_i, index_j, num);

        temp += abs(index_i - indexF_i) + abs(index_j - indexF_j);
    }

    return temp;
}

void DState::expand(vector<DState>& children)
{
    DState child(this->side);

    int x, y;
    findNum(x, y, 0);

    if (this->moveUp(x, y, child)) {
        children.push_back(child);
    }
    if (this->moveRight(x, y, child)) {
        children.push_back(child);
    }
    if (this->moveDown(x, y, child)) {
        children.push_back(child);
    }
    if (this->moveLeft(x, y, child)) {
        children.push_back(child);
    }
}

string DState::myHash() const
{
    string strHash;
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            strHash.append(to_string(board[i * side + j]));
        }
    }
    strHash.shrink_to_fit();
    return strHash;
}

bool DState::isSolvable() const
{
    int invCount = 0;
    int blank;
    for (int i = 0; i < (side * side) - 1; i++) {
        for (int j = i + 1; j < (side * side); j++) {
            if ((board[j] > 0) && (board[i] > 0) && board[i] > board[j]) {
                invCount++;
            }
            if (board[i] == 0) {
                blank = i / side;
            }
        }
    }

    if (side & 1) {
        return !(invCount & 1);
    } else {
        if (blank & 1) {
            return !(invCount & 1);
        } else {
            return invCount & 1;
        }
    }
}