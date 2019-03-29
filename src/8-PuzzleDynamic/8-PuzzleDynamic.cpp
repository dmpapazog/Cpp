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
        // Compute individual hash based on getSum()
        return hash<unsigned long long int>()(k.getSum());
    }
};
}

struct gradeComp
{
    bool operator()(const DState& lhs, const DState& rhs) const
    {
        return (lhs.getGrade() <= rhs.getGrade());
    }
};

void printMenu();
void printSolution(stack<DState>* solution);

void visitedCount(const int& num);

bool BFS(queue<DState>* frontier, unordered_set<DState>* closedSet, const DState& finalDState, stack<DState>* solution);
bool DFS(stack<DState>* frontier, unordered_set<DState>* closedSet, const DState& finalDState, stack<DState>* solution);
bool BestFS(set<DState, gradeComp>* frontier, unordered_set<DState>* closedSet, const DState& finalDState, stack<DState>* solution);

int main()
{
    DState initialDState(N);
    initialDState.setDefaultInitialDState();
    initialDState.show();

    if (!initialDState.isSolvable()) {
        cout << "The problem is unsolvable.\n";

        system("pause");
        return EXIT_FAILURE;
    }

    DState finalDState(N);
    finalDState.setFinalDState();

    unordered_set<DState>* closedSet = new unordered_set<DState>();
    stack<DState>* solution = new stack<DState>();

    int choice = 0;
    printMenu();
    cin >> choice;

    switch (choice) {
    case 1: {
        queue<DState> *frontier = new queue<DState>();

        frontier->push(initialDState);

        if (BFS(frontier, closedSet, finalDState, solution)) {
            cout << "\nA solution was found.\n"
                 << "DStates visited: " << closedSet->size() << '\n'
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
        stack<DState> *frontier = new stack<DState>();

        frontier->push(initialDState);

        if (DFS(frontier, closedSet, finalDState, solution)) {
            cout << "\nA solution was found.\n"
                 << "DStates visited: " << closedSet->size() << '\n'
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
        set<DState, gradeComp> *frontier = new set<DState, gradeComp>();

        frontier->insert(initialDState);

        if (BestFS(frontier, closedSet, finalDState, solution)) {
            cout << "\nA solution was found.\n"
                 << "DStates visited: " << closedSet->size() << '\n'
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

bool BFS(queue<DState>* frontier, unordered_set<DState>* closedSet, const DState& finalDState, stack<DState>* solution)
{
    while (!frontier->empty()) {
        DState *current = new DState(N);
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

bool DFS(stack<DState>* frontier, unordered_set<DState>* closedSet, const DState& finalDState, stack<DState>* solution)
{
    while (!frontier->empty()) {
        DState *current = new DState(N);
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

bool BestFS(set<DState, gradeComp>* frontier, unordered_set<DState>* closedSet, const DState& finalDState, stack<DState>* solution)
{
    while (!frontier->empty()) {
        DState *current = new DState(N);
        *current = *(frontier->begin());
        frontier->erase(frontier->begin());

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

void printSolution(stack<DState> *solution)
{
    int step = 1;
    while (!solution->empty()) {
        DState temp = solution->top();
        cout << "\nStep" << step++ << ":\n";
        temp.show();
        solution->pop();
    }
}