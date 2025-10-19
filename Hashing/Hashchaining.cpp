//Library management using the hash chaining concept
#include <bits/stdc++.h>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

int main() {
    const int SIZE = 10;
    Node* hashTable[SIZE];   
    
   
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = nullptr;
    }

    int choice, bookID;
    while (cin >> choice) {
        if (choice == 1) {
            cin >> bookID;
            int index = (bookID * 7) % SIZE;

            Node* newNode = new Node(bookID);

            if (hashTable[index] == nullptr) {
                hashTable[index] = newNode;
            } else {
              
                Node* temp = hashTable[index];
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
        else if (choice == 2) {
            // display hash table
            for (int i = 0; i < SIZE; i++) {
                cout << i << " ->";
                Node* temp = hashTable[i];
                while (temp != nullptr) {
                    cout << " " << temp->data;
                    temp = temp->next;
                }
                cout << "\n";
            }
            break;
        }
    }
    return 0;
}
