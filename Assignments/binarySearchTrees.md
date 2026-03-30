# Activity 8: Binary Search Trees
----------------------------------

## Tasks

1. Imagine you were to take an empty binary search tree and insert the following sequence of numbers in this order: [1, 5, 9, 2, 4, 10, 6, 3, 8]. Draw a diagram showing what the binary search tree would look like. Remember, the numbers are being inserted in the order presented here. **(2 points)**
<p align="center">
  <img src="https://github.com/jesa06/CISC187/blob/main/Images/binarySearchTree.png" width="400">
</p>
<p align="center"><em>Binary Search Tree</em></p>
<br><br>

2. If a well-balanced binary search tree contains 1,000 values, what is the maximum number of steps it would take to search for a value within it? **(1 point)**
> It would take a maximum of 10 steps to search for a value within it. This is because of the formula log₂(n). Since we are using binary the base would be 2, so log₂(n) would be roughly 9.97...and we can't have part of steps so we would round up to 10!

3. Write an algorithm that finds the greatest value within a binary search tree. **(2 points)**
```cpp
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
```

4. Write a code in C++ using the same array mentioned in #1 and implement a binary search tree. Only insertion operation is required. **(5 points)**
```cpp

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
```

### [Full Code](https://github.com/jesa06/CISC187/blob/main/TestCode/TreeNode.cpp)



