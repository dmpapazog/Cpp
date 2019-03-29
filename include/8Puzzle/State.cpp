#include "State.h"
#include <cstdlib>
#include <ctime>
#include <random>

#include <iostream>

#include <iterator>
#include <set>

#include <climits>
#include <cmath>

using namespace std;

State::State()
{
    initState();
    parent = nullptr;
    grade = INT32_MAX;
}

void State::initState()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = -1;
        }
    }
}

void State::show() const
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|\n";
    }
}

void State::swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool State::findNum(int& x, int& y, const int& num) const
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == num) {
                x = i;
                y = j;
                return true;
            }
        }
    }
    return false;
}

bool State::moveUp(const int& i, const int& j, State& child)
{
    if (i > 0) {
        child = *this;
        child.swap(&child.board[i - 1][j], &child.board[i][j]);

        child.parent = this;
        child.grade = child.setManhattan();
        
        return true;
    }

    return false;
}

bool State::moveRight(const int& i, const int& j, State& child)
{
    if (j < 3 - 1) {
        child = *this;
        child.swap(&child.board[i][j + 1], &child.board[i][j]);

        child.parent = this;
        child.grade = child.setManhattan();

        return true;
    }
    return false;
}

bool State::moveDown(const int& i, const int& j, State& child)
{
    if (i < 3 - 1) {
        child = *this;
        child.swap(&child.board[i + 1][j], &child.board[i][j]);

        child.parent = this;
        child.grade = child.setManhattan();

        return true;
    }
    return false;
}

bool State::moveLeft(const int& i, const int& j, State& child)
{
    if (j > 0) {
        child = *this;
        child.swap(&child.board[i][j - 1], &child.board[i][j]);

        child.parent = this;
        child.grade = child.setManhattan();

        return true;
    }
    return false;
}

bool operator==(const State& lhs, const State& rhs)
{

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (lhs.board[i][j] != rhs.board[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool operator!=(const State& lhs, const State& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const State& lhs, const State& rhs)
{
    return (lhs.getGrade() < rhs.getGrade());
}

bool operator<=(const State& lhs, const State& rhs)
{
    return (lhs.getGrade() <= rhs.getGrade());
}

bool operator>(const State& lhs, const State& rhs)
{
    return !(lhs <= rhs);
}

bool operator>=(const State& lhs, const State& rhs)
{
    return !(lhs < rhs);
}

void State::setFinalState()
{
    int count = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = count++ % 9;
        }
    }

    grade = 0;
}

void State::setDefaultInitialState()
{
    board[0][0] = 6; board[0][1] = 7; board[0][2] = 1;
    board[1][0] = 0; board[1][1] = 3; board[1][2] = 2;
    board[2][0] = 8; board[2][1] = 5; board[2][2] = 4;
    
    parent = nullptr;
    grade = setManhattan();
}

void State::setRandomInitialState()
{
    srand(time(NULL));

    set<int> NUMBERS;
    for (int i = 0; i < 9; i++) {
        NUMBERS.insert(i);
    }

    int randPosition;
    set<int>::iterator it;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            it = NUMBERS.begin();
            randPosition = rand() % NUMBERS.size();
            advance(it, randPosition);
            board[i][j] = *it;
            NUMBERS.erase(it);
        }
    }

    parent = nullptr;
    grade = setManhattan();
}

int State::setManhattan()
{
    int x = 0, y = 0;
    int number = 1;

    int index_i, index_j;

    while (number < 9) {
        findNum(index_i, index_j, number);

        grade += abs(index_i - x) + abs(index_j - y);

        if ((y + 1) > 3) {
            x--;
        }
        y = (y + 1) % 3;
        number++;
    }
    return grade;
}

void State::expand(vector<State>& children)
{
    State child;

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

unsigned long long int State::getSum() const
{
    unsigned long long int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += (i + j) * board[i][j];
        }
    }

    return sum;
}

int State::getInvCount(int* arr) const
{
    int inv_count = 0;
    for (int i = 0; i < 9 - 1; i++) {
        for (int j = i + 1; j < 9; j++) {
            if ((arr[j] > 0) && (arr[i] > 0) && arr[i] > arr[j]) {
                inv_count++;
            }
        }
    }
    return inv_count;
}

bool State::isSolvable() const
{
    int invCount = getInvCount((int*)board);

    return (invCount % 2) == 0;
}
