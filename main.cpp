#include "binarySearchTree.cpp"

using namespace std;

int main()
{
    BinarySearchTree binarySearchTree;

    binarySearchTree.insert(4);
    binarySearchTree.insert(2);
    binarySearchTree.insert(7);
    binarySearchTree.insert(10);

    bool isBinarySearchTree = binarySearchTree.isBinarySearchTree();

    if (isBinarySearchTree)
    {
        cout << "Is a valid binary search tree";
    }
    else
    {
        cout << "Not a valid binary search tree";
    }

    return 0;
}