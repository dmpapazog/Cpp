#include "State.h"
#include <cstdlib>
#include <ctime>
#include <random>

#include <iostream>

#include <set>
#include <iterator>

using namespace std;

State::State()
{
    size = 0;
    parent = nullptr;
}

State::State(int size)
{
    this->size = size;
    board = new int*[size];
    for (int i = 0; i < size; i++) {
        board[i] = new int[size];
    }

    parent = nullptr;
}

void State::setFinalState()
{
    int count = 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = count++ % (size * size);
        }
    }
}

void State::setRandomInitialState()
{
    srand(time(NULL));

    parent = nullptr;

    set<int> NUMBERS;
    for (int i = 0; i < size * size; i++) {
        NUMBERS.insert(i);
    }

    int randPosition;
    set<int>::iterator it;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            it = NUMBERS.begin();
            randPosition = rand() % NUMBERS.size();
            advance(it, randPosition);
            board[i][j] = *it;
            NUMBERS.erase(it);
        }
    }
}

void State::setDefaultInitialState()
{
    board[0][0] = 6; board[0][1] = 7; board[0][2] = 1;
    board[1][0] = 0; board[1][1] = 3; board[1][2] = 2;
    board[2][0] = 8; board[2][1] = 5; board[2][2] = 4;
}

void State::printBoard() const
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
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

bool State::moveUp(int i, int j) const
{
    return i > 0;
}

bool State::moveRight(int i, int j) const
{
    return j < (size - 1);
}

bool State::moveDown(int i, int j) const
{
    return i < (size - 1);
}

bool State::moveLeft(int i, int j) const
{
    return j > 0;
}

void State::expand(queue<State> *frontier)
{
    int x, y;
    bool found = false;
    for (int i = 0; i < size && !found; i++) {
        for (int j = 0; j < size && !found; j++) {
            if (board[i][j] == 0) {
                x = i;
                y = j;
                found = true;
            }
        }
    }

    State tempStates[4];
    for (int i = 0; i < 4; i++) {
        tempStates[i] = *this;
    }

    if (moveUp(x, y)) {
        tempStates[0].swap(&tempStates[0].board[x - 1][y], &tempStates[0].board[x][y]);
        tempStates[0].parent = this;
    }
    if (moveRight(x, y)) {
        tempStates[1].swap(&tempStates[1].board[x][y + 1], &tempStates[1].board[x][y]);
        tempStates[1].parent = this;
    }
    if (moveDown(x, y)) {
        tempStates[2].swap(&tempStates[2].board[x + 1][y], &tempStates[2].board[x][y]);
        tempStates[2].parent = this;
    }
    if (moveLeft(x, y)) {
        tempStates[3].swap(&tempStates[3].board[x][y - 1], &tempStates[3].board[x][y]);
        tempStates[3].parent = this;
    }

    for (int i = 0; i < 4; i++) {
        if (!(tempStates[i] == *this)) {
            frontier->push(tempStates[i]);
        }
    }
}
void State::expand(stack<State> *frontier)
{
    int x, y;
    bool found = false;
    for (int i = 0; i < size && !found; i++) {
        for (int j = 0; j < size && !found; j++) {
            if (board[i][j] == 0) {
                x = i;
                y = j;
                found = true;
            }
        }
    }

    State tempStates[4];
    for (int i = 0; i < 4; i++) {
        tempStates[i] = *this;
    }

    if (moveUp(x, y)) {
        tempStates[0].swap(&tempStates[0].board[x - 1][y], &tempStates[0].board[x][y]);
        tempStates[0].parent = this;
    }
    if (moveRight(x, y)) {
        tempStates[1].swap(&tempStates[1].board[x][y + 1], &tempStates[1].board[x][y]);
        tempStates[1].parent = this;
    }
    if (moveDown(x, y)) {
        tempStates[2].swap(&tempStates[2].board[x + 1][y], &tempStates[2].board[x][y]);
        tempStates[2].parent = this;
    }
    if (moveLeft(x, y)) {
        tempStates[3].swap(&tempStates[3].board[x][y - 1], &tempStates[3].board[x][y]);
        tempStates[3].parent = this;
    }

    for (int i = 0; i < 4; i++) {
        if (tempStates[i] != *this) {
            frontier->push(tempStates[i]);
        }
    }
}

bool State::operator==(const State &right) const
{
    if (size != right.size) {
        return false;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] != right.board[i][j]) {
                return false;
            }
        }
    }

    return true;
}

bool State::operator!=(const State &right) const
{
    return !(*this == right);
}

unsigned long long int State::getSum() const
{
    long long int sum = 0;
    int counter = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sum += counter++ * board[i][j];
        }
    }

    return sum;
}

void State::operator=(const State& right)
{
    this->size = right.size;
    board = new int*[this->size];
    for (int i = 0; i < size; i++) {
        board[i] = new int;
    }

    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            this->board[i][j] = right.board[i][j];
        }
    }

    this->parent = right.parent;
}

int State::getInvCount(int *arr) const
{
    int inv_count = 0;
    for (int i = 0; i < (size * size) - 1; i++) {
        for (int j = i + 1; j < (size * size); j++) {

            if (arr[j] && arr[i] && arr[i] > arr[j]) {
                inv_count++;
            }
        }
    }
    return inv_count;
}

bool State::isSolvable() const
{
    int invCount = getInvCount((int *)board);

    return (invCount % 2) == 0;
}