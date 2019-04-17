#include "cstdlib"
#include "include/AVL/AVL.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <class T>
void find(const AVL<T>& tree, const T& val);

template <class T>
void deleteVal(AVL<T>& tree, const T& val);

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

    num = atoi(argv[1]);
    deleteVal(myTree, 12);
    deleteVal(myTree, 12);
    find(myTree, num);

    cout << "The size of the tree is: " << myTree.getSize();

    myTree.findMin(num);
    cout << "\nThe minimum element of the tree is: " << num;

    inputFile.close();
    return EXIT_SUCCESS;
}

template <class T>
void find(const AVL<T>& tree, const T& val)
{
    if (tree.search(val) == "SUCCESS") {
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