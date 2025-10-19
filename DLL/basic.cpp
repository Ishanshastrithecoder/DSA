// all basic function and operation of Doubly Linked list
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertFront(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteFront() {
        if (!head) {
            cout << "List is Empty" << endl;
            return;
        }
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteLast() {
        if (!tail) {
            cout << "List is Empty" << endl;
            return;
        }
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void insertAfter(int key, int val) {
        Node* curr = head;
        while (curr && curr->data != key) {
            curr = curr->next;
        }
        if (!curr) return;

        Node* newNode = new Node(val);
        newNode->next = curr->next;
        newNode->prev = curr;
        if (curr->next) curr->next->prev = newNode;
        curr->next = newNode;
        if (tail == curr) tail = newNode;
    }

    void display() {
        if (!head) {
            cout << "List is Empty" << endl;
            return;
        }
        Node* curr = head;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void countNodes() {
        int count = 0;
        Node* curr = head;
        while (curr) {
            count++;
            curr = curr->next;
        }
        cout << count << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, val, key;
    while (cin >> choice && choice != 0) {
        switch (choice) {
            case 1:
                cin >> val;
                dll.insertFront(val);
                break;
            case 2:
                cin >> val;
                dll.insertEnd(val);
                break;
            case 3:
                dll.deleteFront();
                break;
            case 4:
                dll.deleteLast();
                break;
            case 5:
                cin >> key >> val;
                dll.insertAfter(key, val);
                break;
            case 6:
                dll.display();
                break;
            case 7:
                dll.countNodes();
                break;
            default:
                break;
        }
    }
    return 0;
}
