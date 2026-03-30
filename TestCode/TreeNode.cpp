#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node() { // default constructor 
        data = 0;
        left = nullptr;
        right = nullptr;
    }
// constructor 
// When defining a constructor inside the struct, you do NOT use "Node::""
    Node(int val, Node* ln = nullptr, Node* rn = nullptr) {
        data = val;
        left = ln;
        right = rn;
    }
};

// Write an algorithm that finds the greatest value within a binary search tree.
// Find maximum value (rightmost node)
int findMax(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return -1;
    }

    while (root->right != nullptr) {
        root = root->right;
    }

    return root->data;
}

// insertion operation 
Node* insert(Node* root, int val) {
    if (root == nullptr)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

int main() {
    int arr[] = {1, 5, 9, 2, 4, 10, 6, 3, 8}; // example array
    int size = 9;

    Node* root = nullptr;

    // Build BST
    for (int i = 0; i < size; i++) {
        root = insert(root, arr[i]);
    }

    cout << "Maximum value: " << findMax(root) << endl;

    return 0;
}