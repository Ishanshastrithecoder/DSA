// QUEUE USING THE LINKEDLIST IMPLEMENTATION WITH BASIC FUNCTIONS
#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};


struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int val) {
    struct node* newnode = new node;
    newnode->data = val;
    newnode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}


int dequeue() {
    if (front == NULL) {
        return -1;
    } else {
        struct node* temp = front;
        int val = temp->data;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
        return val;
    }
}

int peek() {
    if (front == NULL) {
        return -1;
    } else {
        return front->data;
    }
}


int isempty() {
    return front == NULL ? 1 : 0;
}

int main() {
    int d, choice;
    cin >> d;

    for (int i = 0; i < d; i++) {
        cin >> choice;
    
        switch (choice) {
            case 1: {
                int p;
                cin >> p;
                enqueue(p);
                break;
            }
            case 2:
                cout << dequeue() << endl;
                break;

            case 3:
                cout << peek() << endl;
                break;

            case 4:
                cout << isempty() << endl;
                break;
        }
    }

    return 0;
}
