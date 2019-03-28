#include "include/8Puzzle/State.h"
#include <cstdlib>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>

// The side of the board,
// default: 3
#define N 3

using namespace std;

unsigned long long int test = 0;

void printMenu();

void visitedCount();

bool BFS(queue<State>* frontier, unordered_set<State>* closedSet, const State& finalState, stack<State>* solution);
bool DFS(stack<State>* frontier, unordered_set<State>* closedSet, const State& finalState, stack<State>* solution);

int main()
{
    State initialState(N);
    initialState.setDefaultInitialState();
    cout << "Initial state:\n";
    initialState.printBoard();

    if (!initialState.isSolvable()) {
        cout << "The problem is unsolvable.\n";

        system("pause");
        return EXIT_FAILURE;
    }

    State finalState(N);
    finalState.setFinalState();

    unordered_set<State> closedSet;
    stack<State> solution;

    int choice = 0;
    printMenu();
    cin >> choice;

    switch (choice) {
    case 1: {
        queue<State> frontier1;

        frontier1.push(initialState);

        if (BFS(&frontier1, &closedSet, finalState, &solution)) {
            cout << "\nA solution was found.\n"
                 << "States visited: " << test << '\n'
                 << "Solution size: " << solution.size() << '\n\n';
            
            int step = 1;
            while (!solution.empty()) {
                State temp = solution.top();
                cout << "\nStep" << step++ << ":\n";
                temp.printBoard();
                solution.pop();
            }
            system("pause");
            return EXIT_SUCCESS;
        } else {
            cout << "\nThe solution doesn't exist.\n\n";
            system("pause");
            return EXIT_FAILURE;
        }
    }
    case 2: {
        stack<State> frontier2;

        frontier2.push(initialState);

        if (DFS(&frontier2, &closedSet, finalState, &solution)) {
            cout << "\nA solution was found.\n"
                 << "States visited: " << test << '\n'
                 << "Solution size: " << solution.size() << '\n\n';
            // The DFS is not optimal, so the printing
            // of the solution is avoided.

            /* int step = 1;
            while (!solution.empty()) {
                State temp = solution.top();
                cout << "\nStep" << step++ << ":\n";
                temp.printBoard();
                solution.pop();
            } */
            system("pause");
            return EXIT_SUCCESS;
        } else {
            cout << "\nThe solution doesn't exist.\n\n";
            system("pause");
            return EXIT_FAILURE;
        }
    }

    default: {
        cout << "\nUnsupported choise. Exiting...\n\n";
        system("pause");
        return EXIT_FAILURE;
    }
    }
}

bool BFS(queue<State>* frontier, unordered_set<State>* closedSet, const State& finalState, stack<State>* solution)
{
    while (!frontier->empty()) {
        State* current = new State(N);
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

bool DFS(stack<State>* frontier, unordered_set<State>* closedSet, const State& finalState, stack<State>* solution)
{
    while (!frontier->empty()) {
        State* current = new State(N);
        *current = frontier->top();
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

void printMenu()
{
    cout << "\nSelect the preferable search algorithm\n";
    cout << "1: BFS\n";
    cout << "2: DFS\n";
    cout << "4: Exit\n";
    cout << "Choice-> ";
}