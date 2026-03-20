#include "Stack.h"
#include <iostream>
using namespace std;

int main() {
    // TEST WITH INT STACK
    cout << "Creating an integer stack..." << endl;
    Stack<int> s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);

    s1.display();

    s1.pop();

    cout << "\nTop element (after pop): " << s1.peek() << endl;

    s1.display();

    cout << "\nCreating a double stack..." << endl;
    // TEST WITH DOUBLE STACK
    Stack<double> s2;
    s2.push(1.5);
    s2.push(20.7);
    s2.push(333.3);
    s2.push(40.1);

    s2.display();

    s2.pop();

    cout << "\nTop element (after pop): " << s2.peek() << endl;

    s2.display();

    cout << "\nCreating a string stack..." << endl;
    // TEST WITH STRING STACK
    Stack<string> s3;
    s3.push("red");
    s3.push("green");
    s3.push("blue");
    s3.push("purple");

    s3.display();

    s3.pop();

    cout << "\nTop element (after pop): " << s3.peek() << endl;

    s3.display();
    return 0;
}