#include "cstdlib"
#include "include/AVL/AVL.hpp"
#include <iostream>

using namespace std;

template <class T>
void find(const AVL<T>& tree, const T& val);

template <class T>
void deleteVal(AVL<T>& tree, const T& val);

int main()
{
    AVL<int> myTree(0);

    int test = 2;
    find(myTree, test);

    myTree.insert(1);
    myTree.insert(2);
    myTree.insert(3);
    myTree.insert(4);
    myTree.insert(5);
    myTree.insert(6);
    myTree.insert(7);
    myTree.insert(8);
    myTree.insert(9);
    myTree.insert(10);
    myTree.insert(11);
    myTree.insert(12);

    // test = 4;
    // find(myTree, test);
    // test = 11;
    // find(myTree, test);

    deleteVal(myTree, 9);
    deleteVal(myTree, 6);
    deleteVal(myTree, 9);

    cout << "The size of the tree is: " << myTree.getSize();

    myTree.findMin(test);
    cout << "\nThe minimum element of the tree is: " << test;

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