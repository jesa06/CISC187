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