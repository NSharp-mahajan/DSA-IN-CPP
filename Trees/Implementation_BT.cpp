#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    cout << "Root value: " << root->data << endl;
    cout << "Parent value: " << root -> left -> data << endl;
    cout << "Parent Value 2 : " << root -> right -> data << endl;
    cout << "Child Value: " << root -> left -> right -> data << endl;

    return 0;
}