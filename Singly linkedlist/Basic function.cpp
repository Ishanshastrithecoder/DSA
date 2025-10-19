/* IT CONTAINS ALL TYPE OF THE BASIC FUCNTION LIKE INSERT, DELETE,  .
    so refer the fuction of the logic behind the fucntion.s
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertFront(int val) {
    Node* newNode = new Node{val, head};
    head = newNode;
}

void insertEnd(int val) {
    Node* newNode = new Node{val, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void insertAfter(int after, int val) {
    Node* temp = head;
    while (temp) {
        if (temp->data == after) {
            Node* newNode = new Node{val, temp->next};
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    }
}

void deleteFront() {
    if (!head) {
        cout << "List is Empty" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteLast() {
    if (!head) {
        cout << "List is Empty" << endl;
        return;
    }
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next)
        temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

void display() {
    if (!head) {
        cout << "List is Empty" << endl;
        return;
    }
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice;
    while (cin >> choice && choice != 0) {
        switch (choice) {
            case 1: {
                int val;
                cin >> val;
                insertFront(val);
                break;
            }
            case 2: {
                int val;
                cin >> val;
                insertEnd(val);
                break;
            }
            case 3: {
                int after, val;
                cin >> after >> val;
                insertAfter(after, val);
                break;
            }
            case 4:
                deleteFront();
                break;
            case 5:
                deleteLast();
                break;
            case 6:
                display();
                break;
        }
    }
    return 0;
}

