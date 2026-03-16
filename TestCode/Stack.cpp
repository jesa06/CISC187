// Part 1: Define the Node Structure
struct Node {
    int data;
    Node* next;
};

// Part 2: Create the Stack Class
class Stack {
    private:
        Node* top;

    public:
        Stack();

        void push(int value);
        void pop();
        int peek();
        bool isEmpty();
        void display();
};

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
    if (top == nullptr) {
        return;
    } else {
        // Remove the top node
        // Update the top pointer
        // Free the memory
    }
    
}
