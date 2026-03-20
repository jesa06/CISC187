#include <iostream>
#include <string>
using namespace std;

 // Part 1: Define the Node Structure
template <class T> 
struct Node {
    T data;
    Node<T>* next;
};

// Part 2: Create the Stack Class
template <class T> 
class Stack {
    private:
        Node<T>* top;

    public:
        Stack();

        void push(T data);
        void pop();
        T peek();
        bool isEmpty();
        void display();
};

// Part 3: Implement the Constructor
template <class T>
Stack<T>::Stack() {
    top = nullptr;
}

// Part 4: Implement push()
template <class T>
void Stack<T>::push(T data) {
    //Create a new node
    Node<T>* newN = new Node<T>;
    // Store the value
    newN->data = data;
    // Set its next pointer to current top
    newN->next = top;
    // Update top pointer
    top = newN;
}

// Part 5: Implement pop()
template <class T>
void Stack<T>::pop() {
    // Check if stack is empty
    if (top == nullptr) { // Part 10: Additional Requirement: Handle stack underflow.
        cout << "Stack Underflow." << endl;
        return;
    } else {
        // Remove the top node
        Node<T>* temp = top;
        top = top->next; // Update the top pointer
        delete temp; // remove it from/Free the memory
    }
    
}

// Part 6: Implement peek()
template <class T>
T Stack<T>::peek() {
    if (top == nullptr) {
        cout << "Stack is empty\n";
        return T();  // Return a default-constructed T instead of -1
    }
    return top->data;
}

// Part 7: Implement isEmpty()
template <class T>
bool Stack<T>::isEmpty() {
    return top == nullptr;
}

// Part 8: Implement display()
template <class T>
void Stack<T>::display() {
    cout << "Stack Elements: " << endl;
    Node<T>* temp = top;

    while (temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

