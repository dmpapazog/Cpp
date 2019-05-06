#include "cstdlib"
#include "AVL/AVL.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <class T>
void find(const AVL<T>& tree, const T& val);

template <class T>
void deleteVal(AVL<T>& tree, const T& val);

template <class T>
void printInOrder(AVL<T>& tree);

template <class T>
void printPreOrder(AVL<T>& tree);

template <class T>
void printPostOrder(AVL<T>& tree);

int main(int argc, char const *argv[])
{
    ifstream inputFile;
    inputFile.open("..\\data\\integers.txt");

    if (!inputFile.is_open()) {
        return EXIT_FAILURE;
    }

    int num;
    string line;
    AVL<int> myTree;
    while (getline(inputFile, line)) {
        num = stoi(line);
        myTree.insert(num);
    }

    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            num = atoi(argv[i]);
            deleteVal(myTree, num);
        }
    }

    cout << "The size of the tree is: " << myTree.getSize();

    if (myTree.findMin(num)) {
        cout << "\nThe minimum element of the tree is: " << num;
    }
    if (myTree.findMax(num)) {
        cout << "\nThe maximum element of the tree is: " << num;
    }
    printPreOrder(myTree);
    printInOrder(myTree);
    printPostOrder(myTree);

    inputFile.close();
    return EXIT_SUCCESS;
}

template <class T>
void find(const AVL<T>& tree, const T& val)
{
    if (tree.search(val) == "SUCCESS"s) {
        cout << val << " is in the tree.\n";
    } else {
        cout << val << " is not in the tree.\n";
    }
}

template <class T>
void deleteVal(AVL<T>& tree, const T& val)
{
    if (tree.deleteNum(val)) {
        cout << val << " is deleted from the tree.\n";
    } else {
        cout << val << " is not in the tree.\n";
    }
}

template <class T>
void printInOrder(AVL<T>& tree)
{
    cout << "In   - order:";
    tree.printIn();
    cout << '\n';
}

template <class T>
void printPreOrder(AVL<T>& tree)
{
    cout << "\nPre  - order:";
    tree.printPre();
    cout << '\n';
}

template <class T>
void printPostOrder(AVL<T>& tree)
{
    cout << "Post - order:";
    tree.printPost();
    cout << '\n';
}