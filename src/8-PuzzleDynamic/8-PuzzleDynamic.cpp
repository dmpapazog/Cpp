#include "include/8Puzzle-dynamic/DState.h"
#include <cstdlib>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_set>
#include <vector>

#define N 3

using namespace std;

namespace std {
template <>
struct hash<DState> {
    size_t operator()(const DState& k) const
    {
        // Compute individual hash based on myHash()
        return hash<string>{}(k.myHash());
    }
};
}

void printMenu();
void printSolution(stack<DState, vector<DState>>* solution);
void printStatistics(unordered_set<DState>* closedSet, stack<DState, vector<DState>>* solution);

void visitedCount(const int& num);

bool BFS(queue<DState>* frontier, unordered_set<DState>* closedSet, const DState& finalDState, stack<DState, vector<DState>>* solution);
bool DFS(stack<DState, vector<DState>>* frontier, unordered_set<DState>* closedSet, const DState& finalDState, stack<DState, vector<DState>>* solution);
bool BestFS(priority_queue<DState, deque<DState>, greater<DState>>* frontier, unordered_set<DState>* closedSet, const DState& finalDState, stack<DState, vector<DState>>* solution);

int main()
{
    char choice;
    cout << "What is the initial state?\n";
    cout << "1: Default initial state.\n";
    cout << "2: Random initial state.\n";
    cout << "Choice-> ";
    cin >> choice;

    DState initialDState(N);
    switch (choice) {
        case '1': {
            initialDState.setDefaultInitialDState();
            break;
        }
        case '2': {
            initialDState.setRandomInitialDState();
            break;
        }
        default: {
            cout << "Unsopported choice. Exiting...";
            return EXIT_FAILURE;
        }
    }
    initialDState.show();

    if (!initialDState.isSolvable()) {
        cout << "The problem is unsolvable.\n";

        system("pause");
        return EXIT_FAILURE;
    }

    DState finalDState(N);
    finalDState.setFinalDState();

    unordered_set<DState>* closedSet = new unordered_set<DState>();
    stack<DState, vector<DState>>* solution = new stack<DState, vector<DState>>();

    choice = '0';
    while (1) {
        printMenu();
        cin >> choice;
        closedSet->clear();

        switch (choice) {
        case '1': {
            queue<DState>* frontier = new queue<DState>();

            frontier->push(initialDState);

            if (BFS(frontier, closedSet, finalDState, solution)) {
                cout << "\n\nBFS found a solution.\n";
                printStatistics(closedSet, solution);
                printSolution(solution);
            } else {
                cout << "\n\nBFS didn't find a solution.\n";
            }
            break;
        }
        case '2': {
            stack<DState, vector<DState>>* frontier = new stack<DState, vector<DState>>();

            frontier->push(initialDState);

            if (DFS(frontier, closedSet, finalDState, solution)) {
                cout << "\n\nDFS found a solution.\n";
                printStatistics(closedSet, solution);
                printSolution(solution);
            } else {
                cout << "\n\nDFS didn't find a solution.\n";
            }
            break;
        }
        case '3': {
            priority_queue<DState, deque<DState>, greater<DState>>* frontier = new priority_queue<DState, deque<DState>, greater<DState>>();

            frontier->push(initialDState);

            if (BestFS(frontier, closedSet, finalDState, solution)) {
                cout << "\nBestFS found a solution.\n";
                printStatistics(closedSet, solution);
                printSolution(solution);
            } else {
                cout << "\n\nBestFS didn't find a solution.\n";
            }
            break;
        }
        case '4': {
            cout << "\nExiting...\n";
            system("pause");
            return EXIT_SUCCESS;
        }
        default: {
            cout << "\nUnsupported choise\n\n";
        }
        }
    }
}

bool BFS(queue<DState>* frontier, unordered_set<DState>* closedSet, const DState& finalDState, stack<DState, vector<DState>>* solution)
{
    while (!frontier->empty()) {
        DState* current = new DState(N);
        *current = frontier->front();
        frontier->pop();

        if (*current == finalDState) {
            while (current->getParent() != nullptr) {
                solution->push(*current);
                current = current->getParent();
            }
            return true;
        }

        if (closedSet->find(*current) != closedSet->end()) {
            continue;
        }

        vector<DState> children;
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

bool DFS(stack<DState, vector<DState>>* frontier, unordered_set<DState>* closedSet, const DState& finalDState, stack<DState, vector<DState>>* solution)
{
    while (!frontier->empty()) {
        DState* current = new DState(N);
        *current = frontier->top();
        frontier->pop();

        if (*current == finalDState) {
            while (current->getParent() != nullptr) {
                solution->push(*current);
                current = current->getParent();
            }
            return true;
        }

        if (closedSet->find(*current) != closedSet->end()) {
            continue;
        }

        vector<DState> children;
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

bool BestFS(priority_queue<DState, deque<DState>, greater<DState>>* frontier, unordered_set<DState>* closedSet, const DState& finalDState, stack<DState, vector<DState>>* solution)
{
    while (!frontier->empty()) {
        DState* current = new DState(N);
        *current = frontier->top();
        frontier->pop();

        if (*current == finalDState) {
            while (current->getParent() != nullptr) {
                solution->push(*current);
                current = current->getParent();
            }
            return true;
        }

        if (closedSet->find(*current) != closedSet->end()) {
            continue;
        }

        vector<DState> children;
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

void visitedCount(const int& num)
{
    if ((num % 1000) == 0)
        cout << "Visit number: " << num << '\r' << flush;
}

void printMenu()
{
    cout << "\nSelect the search algorithm\n";
    cout << "1: BFS\n";
    cout << "2: DFS\n";
    cout << "3: BestFS\n";
    cout << "4: Exit\n";
    cout << "Choice-> ";
}

void printSolution(stack<DState, vector<DState>>* solution)
{
    char choice;
    cout << "Do you want to print the solution?\n";
    cout << "[y]es or [n]o: ";
    cin >> choice;
    switch (choice) {
    case 'y': {
        int step = 1;
        while (!solution->empty()) {
            DState temp = solution->top();
            cout << "\nStep " << step++ << " : " << temp.getMove() << '\n';
            temp.show();
            solution->pop();
        }
        break;
    }
    default: {
        while (!solution->empty()) {
            solution->pop();
        }
    }
    }
}

void printStatistics(unordered_set<DState>* closedSet, stack<DState, vector<DState>>* solution)
{
    cout << "Closed set: " << closedSet->size() << '\n'
         << "Solution size: " << solution->size() << '\n';
}