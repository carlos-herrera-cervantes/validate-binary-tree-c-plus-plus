#include <iostream>
#include "treeNode.cpp"

using namespace std;

class BinarySearchTree
{

    Node *root;
    int length;

    /**
     * Prints the elements
     * @param node Node object class
     * @returns Void
    */
    void inorder(Node *node)
    {
        if (!node)
            return;

        cout << node->data << ": ";

        if (node->left)
            cout << "L" << node->left->data << " ";
        if (node->rigth)
            cout << "R" << node->rigth->data << " ";

        cout << endl;

        inorder(node->left);
        inorder(node->rigth);
    }

    /** Inserts a new node
     * @param node Node object class
     * @param value Number value
     * @returns Node object class
    */
    Node* insert(Node* node, int value)
    {
        if (!node)
        {
            node = new Node();
            node->data = value;
            node->left = node->rigth = NULL;
        }
        else if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else if (value > node->data)
        {
            node->rigth = insert(node->rigth, value);
        }

        return node;
    }

    /**
     * Checks if tree is a valid binary search tree
     * @param node Node object class
     * @param min Value of node
     * @param max Value of node
     * @returns If is a valid binary search tree returns true otherwise false
     */
    bool validateBinarySearchTree(Node* node, int min, int max)
    {
        if (!node) return true;

        bool minimum = min && node->data <= min;
        bool maximum = max && node->data > max;
        
        if (minimum || maximum) return false;

        if (!validateBinarySearchTree(node->left, min, node->data))
        {
            return false;
        }

        return true;
    }

    public:

        BinarySearchTree()
        {
            root = NULL;
            length = 0;
        }

        /**
         * Prints the elements to the console
         * @returns Void
         */
        void print()
        {
            inorder(root);
            cout << endl;
        }

        /**
         * Inserts a new value
         * @param data Number value
         * @returns Void
         */
        void insert(int data)
        {
            root = insert(root, data);
            length++;
        }

        /**
         * Checks if tree is a valid binary search tree
         * @returns If is a valid binary search tree returns true otherwise false
         */
        bool isBinarySearchTree()
        {
            return validateBinarySearchTree(root, 0, 0);
        }
};