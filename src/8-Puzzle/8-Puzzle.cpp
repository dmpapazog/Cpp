#include "include/8Puzzle/State.h"
#include <cstdlib>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;

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

struct gradeComp
{
    bool operator()(const State& lhs, const State& rhs) const
    {
        return lhs <= rhs;
    }
};

void printMenu();
void printSolution(stack<State>* solution);

void visitedCount(const int& num);

bool BFS(queue<State>* frontier, unordered_set<State>* closedSet, const State& finalState, stack<State>* solution);
bool DFS(stack<State>* frontier, unordered_set<State>* closedSet, const State& finalState, stack<State>* solution);
bool BestFS(set<State, gradeComp>* frontier, unordered_set<State>* closedSet, const State& finalState, stack<State>* solution);

int main()
{
    State initialState;
    initialState.setDefaultInitialState();
    initialState.show();

    if (!initialState.isSolvable()) {
        cout << "The problem is unsolvable.\n";

        system("pause");
        return EXIT_FAILURE;
    }

    State finalState;
    finalState.setFinalState();
    finalState.show();

    unordered_set<State>* closedSet = new unordered_set<State>();
    stack<State>* solution = new stack<State>();

    int choice = 0;
    printMenu();
    cin >> choice;

    switch (choice) {
    case 1: {
        queue<State> *frontier = new queue<State>();

        frontier->push(initialState);

        if (BFS(frontier, closedSet, finalState, solution)) {
            cout << "\nA solution was found.\n"
                 << "States visited: " << closedSet->size() << '\n'
                 << "Solution size: " << solution->size() << "\n\n";
            printSolution(solution);
            system("pause");
            return EXIT_SUCCESS;
        } else {
            cout << "\nThe solution doesn't exist.\n\n";
            system("pause");
            return EXIT_FAILURE;
        }
    }
    case 2: {
        stack<State> *frontier = new stack<State>();

        frontier->push(initialState);

        if (DFS(frontier, closedSet, finalState, solution)) {
            cout << "\nA solution was found.\n"
                 << "States visited: " << closedSet->size() << '\n'
                 << "Solution size: " << solution->size() << "\n\n";
            // printSolution(solution);
            system("pause");
            return EXIT_SUCCESS;
        } else {
            cout << "\nThe solution doesn't exist.\n\n";
            system("pause");
            return EXIT_FAILURE;
        }
    }
    case 3: {
        set<State, gradeComp> *frontier = new set<State, gradeComp>();

        frontier->insert(initialState);

        if (BestFS(frontier, closedSet, finalState, solution)) {
            cout << "\nA solution was found.\n"
                 << "States visited: " << closedSet->size() << '\n'
                 << "Solution size: " << solution->size() << "\n\n";
            printSolution(solution);
            system("pause");
            return EXIT_SUCCESS;
        } else {
            cout << "\nThe solution doesn't exist.\n\n";
            system("pause");
            return EXIT_FAILURE;
        }
    }
    case 4: {
        cout << "\nExiting...\n";
        system("pause");
        return EXIT_SUCCESS;
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
        State *current = new State();
        *current = frontier->front();
        frontier->pop();

        if (*current == finalState) {
            while (current->getParent() != nullptr) {
                solution->push(*current);
                current = current->getParent();
            }
            return true;
        }

        if (closedSet->find(*current) != closedSet->end()) {
            continue;
        }

        vector<State> children;
        current->expand(children);

        for (size_t i = 0; i < children.size(); i++) {
            frontier->push(children.at(i));
        }

        closedSet->insert(*current);
        visitedCount(closedSet->size());
        children.clear();
    }
    return false;
}

bool DFS(stack<State>* frontier, unordered_set<State>* closedSet, const State& finalState, stack<State>* solution)
{
    while (!frontier->empty()) {
        State *current = new State();
        *current = frontier->top();
        frontier->pop();

        if (*current == finalState) {
            while (current->getParent() != nullptr) {
                solution->push(*current);
                current = current->getParent();
            }
            return true;
        }

        if (closedSet->find(*current) != closedSet->end()) {
            continue;
        }

        vector<State> children;
        current->expand(children);

        for (size_t i = 0; i < children.size(); i++) {
            frontier->push(children.at(i));
        }

        closedSet->insert(*current);
        visitedCount(closedSet->size());
        children.clear();
    }

    return false;
}

bool BestFS(set<State, gradeComp>* frontier, unordered_set<State>* closedSet, const State& finalState, stack<State>* solution)
{
    while (!frontier->empty()) {
        State *current = new State();
        *current = *(frontier->begin());
        frontier->erase(frontier->begin());

        if (*current == finalState) {
            while (current->getParent() != nullptr) {
                solution->push(*current);
                current = current->getParent();
            }
            return true;
        }

        if (closedSet->find(*current) != closedSet->end()) {
            continue;
        }

        vector<State> children;
        current->expand(children);

        for (size_t i = 0; i < children.size(); i++) {
            frontier->insert(children.at(i));
        }

        closedSet->insert(*current);
        visitedCount(closedSet->size());
        children.clear();

    }
    return false;
}

void visitedCount(const int& num)
{
    cout << "Visit number: " << num << '\r' << flush;
}

void printMenu()
{
    cout << "\nSelect the preferable search algorithm\n";
    cout << "1: BFS\n";
    cout << "2: DFS\n";
    cout << "3: BestFS\n";
    cout << "4: Exit\n";
    cout << "Choice-> ";
}

void printSolution(stack<State> *solution)
{
    int step = 1;
    while (!solution->empty()) {
        State temp = solution->top();
        cout << "\nStep" << step++ << ":\n";
        temp.show();
        solution->pop();
    }
}