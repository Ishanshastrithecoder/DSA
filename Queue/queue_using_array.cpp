//   QUEUE IS IMPLEMENTED USNG THE ARRAY WITH ALL BASIC FUNCTION LIKE ENQUEUE,DEQUEUE,ISEMPTY,PEEK ETC.
#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;  
int queue[MAX_SIZE];
int front = 0, rear = 0;

void enqueue(int element) {
    if (rear == MAX_SIZE) {
        cout << "Queue Overflow"; 
        return;
    }
    queue[rear++] = element;
}

int dequeue() {
    if (front == rear) {
        return -1; 
    }
    return queue[front++];
}

int peek() {
    if (front == rear) {
        return -1;  
    }
    return queue[front];
}

int isempty() {
    if (front == rear) {
        return 1;  
    }
    else {
        return 0;
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int choice;
        cin >> choice;

        switch(choice) {
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
