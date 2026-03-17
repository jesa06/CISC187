#include "Stack.h"
#include <iostream>
using namespace std;


// Part 3: Implement the Constructor
Stack::Stack() {
    top = nullptr;
}

// Part 4: Implement push()
void Stack::push(int value) {
    //Create a new node
    Node* newN = new Node;
    // Store the value
    newN->data = value;
    // Set its next pointer to current top
    newN->next = top;
    // Update top pointer
    top = newN;
}

// Part 5: Implement pop()
void Stack::pop() {
    // Check if stack is empty
    if (top == nullptr) { // Part 10: Additional Requirement: Handle stack underflow.
        cout << "Stack Underflow." << endl;
        return;
    } else {
        // Remove the top node
        Node* temp = top;
        top = top->next; // Update the top pointer
        delete temp; // remove it from/Free the memory
    }
    
}

// Part 6: Implement peek()
int Stack::peek() {
    if (top == nullptr) {
        cout << "Stack is empty\n";
        return -1;  // or throw an error
    }
    return top->data;
}

// Part 7: Implement isEmpty()
bool Stack::isEmpty() {
    return top == nullptr;
}

// Part 8: Implement display()
void Stack::display() {
    cout << "Stack Elements: " << endl;
    Node* temp = top;

    while (temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

