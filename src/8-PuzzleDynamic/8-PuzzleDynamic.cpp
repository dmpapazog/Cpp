#include "8Puzzle-dynamic/DState.h"
#include <cstdlib>
#include <iostream>
#include <queue>
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

typedef stack<DState, vector<DState>> Stack;
typedef unordered_set<DState> Set;
typedef queue<DState> Queue;
typedef priority_queue<DState, deque<DState>, greater<DState>> PrioQueue;

void printMenu();
void printSolution(Stack* solution);
void printStatistics(Set* closedSet, Stack* solution);

void visitedCount(const int& num);

bool BFS(Queue* frontier, Set* closedSet, const DState& finalDState, Stack* solution);
bool DFS(Stack* frontier, Set* closedSet, const DState& finalDState, Stack* solution);
bool BestFS(PrioQueue* frontier, Set* closedSet, const DState& finalDState, Stack* solution);

int main()
{
    char choice;
    if (N == 3) {
        cout << "What is the initial state?\n";
        cout << "1: Default initial state.\n";
        cout << "2: Random initial state.\n";
        cout << "Choice-> ";
        cin  >> choice;
    } else {
        choice = '2';
    }

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

    auto closedSet = new Set();
    auto solution  = new Stack();

    choice = '0';
    while (1) {
        printMenu();
        cin >> choice;
        closedSet->clear();

        switch (choice) {
        case '1': {
            auto frontier = new Queue();

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
            auto frontier = new Stack();

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
            auto frontier = new PrioQueue();

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

bool BFS(Queue* frontier, Set* closedSet, const DState& finalDState, Stack* solution)
{
    while (!frontier->empty()) {
        auto current = new DState(N);
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

bool DFS(Stack* frontier, Set* closedSet, const DState& finalDState, Stack* solution)
{
    while (!frontier->empty()) {
        auto current = new DState(N);
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

bool BestFS(PrioQueue* frontier, Set* closedSet, const DState& finalDState, Stack* solution)
{
    while (!frontier->empty()) {
        auto current = new DState(N);
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
    cin  >> choice;
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
    cout << "Closed set: "    << closedSet->size() << '\n'
         << "Solution size: " <<  solution->size() << '\n';
}