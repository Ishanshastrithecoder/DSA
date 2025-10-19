// Binary tree traversal it has 4 tyoe of the  traversal 1) preorder 2) postorder 3)inorder 4)level-order using the queue
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

const int MAX_SIZE = 10000;
int nodes[MAX_SIZE];
int n = 0;

Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* buildTree(int& index) {
    if (index >= n || nodes[index] == -1) {
        index++;
        return nullptr;
    }
    
    Node* root = createNode(nodes[index]);
    index++;
    root->left = buildTree(index);
    root->right = buildTree(index);
    return root;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*>q;
    
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

int main() {
    int val;
    while (cin >> val) {
        nodes[n++] = val;
    }
    
    int index = 0;
    Node* root = buildTree(index);
    
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    levelOrder(root);
    cout << endl;

    return 0;
}
