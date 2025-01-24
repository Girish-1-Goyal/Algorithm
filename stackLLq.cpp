/*
*
*    Author : Girish Kumar Goyal.
*
*/

#include <bits/stdc++.h>

using namespace std;

// implement a stack using a linked list

class Node {
public:
    int data;       // Data part of the node
    Node* next;     // Pointer to the next node

    // Constructor to initialize a new node
    Node(int value) : data(value), next(nullptr) {}
};

// Stack class implemented using a linked list
class Stack {
private:
    Node* topNode;  // Pointer to the top of the stack

public:
    // Constructor: Initialize an empty stack
    Stack() : topNode(nullptr) {}

    // Destructor: Free all allocated memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Push a new element onto the stack
    void push(int value) {
        Node* newNode = new Node(value); // Create a new node
        newNode->next = topNode;        // Link the new node to the current top
        topNode = newNode;              // Update the top pointer
    }

    // Pop the top element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop!" << endl;
            return;
        }
        Node* temp = topNode;           // Store the top node to delete
        topNode = topNode->next;        // Move the top pointer to the next node
        delete temp;                    // Free memory for the popped node
    }

    // Get the top element of the stack
    int top() const {
        if (isEmpty()) {
            throw runtime_error("Stack is empty. No top element!");
        }
        return topNode->data;           // Return the data of the top node
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return topNode == nullptr;
    }

    // Display all elements in the stack
    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* current = topNode;        // Start from the top of the stack
        cout << "Stack elements: ";
        while (current != nullptr) {   // Traverse the linked list
            cout << current->data << " ";
            current = current->next;   // Move to the next node
        }
        cout << endl;
    }
};

// implement a stack using queue

class Stack {
private:
    queue<int> q; // Single queue

public:
    // Push an element onto the stack
    void push(int value) {
        q.push(value); // Push the new element to the queue

        // Rearrange the queue so the last added element becomes the front
        int size = q.size();
        for (int i = 1; i < size; ++i) {
            q.push(q.front()); // Move the front element to the back
            q.pop();
        }
    }

    // Pop the top element from the stack
    void pop() {
        if (q.empty()) {
            cout << "Stack is empty. Cannot pop!" << endl;
            return;
        }
        q.pop();
    }

    // Get the top element of the stack
    int top() const {
        if (q.empty()) {
            throw runtime_error("Stack is empty. No top element!");
        }
        return q.front();
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return q.empty();
    }

    // Get the size of the stack
    size_t size() const {
        return q.size();
    }
};


void solve(){
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    cout << "Top element: " << stack.top() << endl;

    stack.pop();
    stack.display();

    cout << "Top element: " << stack.top() << endl;

    stack.pop();
    stack.pop();
    stack.pop();
}

void init_code(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    init_code();
    solve();
    return 0;
}
