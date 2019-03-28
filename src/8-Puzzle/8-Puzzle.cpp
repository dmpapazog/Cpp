#include <iostream>
#include <cstdlib>
#include <queue>
#include <unordered_set>
#include <stack>
#include "include/8Puzzle/State.h"


// The side of the board,
// default: 3
#define N 3


using namespace std;

unsigned long long int test = 0;

void visitedCount();

bool BFS(queue<State> *frontier, unordered_set<State> *closedSet, const State& finalState, stack<State> *solution);

int main()
{
    State initialState(N);
    initialState.setInitialState();
    cout << "Initial state:\n";
    initialState.printBoard();


    if (!initialState.isSolvable()) {
        cout << "The problem is unsolvable.\n";

        return EXIT_FAILURE;
    }

    State finalState(N);
    finalState.setFinalState();

    queue<State> frontier;
    unordered_set<State> closedSet;

    stack<State> solution;

    frontier.push(initialState);

    if (BFS(&frontier, &closedSet, finalState, &solution)) {
        cout << "A solution was found.\n" << "States visited: " << test << '\n';
        int step = 1;
        while (!solution.empty()) {
            State temp = solution.top();
            cout << "\nStep" << step++ << ":\n";
            temp.printBoard();
            solution.pop();
        }
    } else {
        cout << "The solution doesn't exist.\n";
    }

    return EXIT_SUCCESS;
}

bool BFS(queue<State> *frontier, unordered_set<State> *closedSet, const State &finalState, stack<State> *solution)
{
    while (!frontier->empty()) {
        State *current = new State(N);
        *current = frontier->front();
        frontier->pop();

        if (closedSet->find(*current) != closedSet->end()) {
            continue;
        }
        visitedCount();

        if (*current == finalState) {
            while (current->getParent() != nullptr) {
                solution->push(*current);
                current = current->getParent();
            }
            return true;
        }

        current->expand(frontier);

        closedSet->insert(*current);
    }

    return false;
}

void visitedCount()
{
    cout << "Visit number: " << test++ << '\r' << flush;
}