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

// int test = 0;

bool BFS(queue<State> *frontier, unordered_set<State> *closedSet, const State& finalState, stack<State> *solution);

int main()
{
    State initialState(N);
    initialState.setInitialState();
    cout << "Initial state:\n";
    initialState.printBoard();


    if (!initialState.isSolvable()) {
        cout << "Computing another initial state.\n";

        return EXIT_FAILURE;
    }

    State finalState(N);
    finalState.setFinalState();

    cout << "\nFinal state:\n";
    finalState.printBoard();

    queue<State> frontier;
    unordered_set<State> closedSet;

    stack<State> solution;

    frontier.push(initialState);

    if (BFS(&frontier, &closedSet, finalState, &solution)) {
        cout << "A solution was found.\n";
        while (!solution.empty()) {
            State temp = solution.top();
            temp.printBoard();
            cout << "\nNEXT\n";
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
        closedSet->insert(*current);

        if (*current == finalState) {
            while (current->getParent() != nullptr) {
                solution->push(*current);
                current = current->getParent();
            }
            return true;
        }

        current->expand(frontier, closedSet);

        closedSet->insert(*current);
        frontier->pop();
        
        // test++;
        // if (test > 100) {
        //     break;
        // }
    }

    return false;
}