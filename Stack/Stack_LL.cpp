//stack implementation using the linkedlist
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;

void push(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == nullptr) {
        cout << "underflow\n";
    } else {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

void display() {
    Node* temp = top;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    int choice, value;

    while (true) {
        cin >> choice;
        if (choice == 0) break;

        switch (choice) {
            case 1:
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}
