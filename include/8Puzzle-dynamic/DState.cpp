#include "DState.h"
#include <cstdlib>
#include <ctime>
#include <random>

#include <iostream>

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
            cout << "| " << board[i * side + j] << " ";
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

        return true;
    }
    return false;
}

bool operator==(const DState& lhs, const DState& rhs)
{
    if (lhs.side == rhs.side) {
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
    int x = 0, y = 0;
    int number = 1;

    int index_i, index_j;

    while (number < (side * side)) {
        findNum(index_i, index_j, number);

        grade += abs(index_i - x) + abs(index_j - y);

        if ((y + 1) > side) {
            x++;
        }
        y = (y + 1) % side;
        number++;
    }
    return grade;
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

unsigned long long int DState::getSum() const
{
    unsigned long long int sum = 0;
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            sum += (i + j) * board[i * side + j];
        }
    }

    return sum;
}

bool DState::isSolvable() const
{
    int invCount = 0;
    for (int i = 0; i < (side * side) - 1; i++) {
        for (int j = i + 1; j < (side * side); j++) {
            if ((board[j] > 0) && (board[i] > 0) && board[i] > board[j]) {
                invCount++;
            }
        }
    }
    return (invCount % 2) == 0;
}