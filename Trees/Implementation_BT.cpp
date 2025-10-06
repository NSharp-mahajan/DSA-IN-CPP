/*#include <iostream>
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
}*/

// ------------------Basic Questions ---------------------//
/*
        1
       / \         Tasks to perform:Print root node’s data, Print its left and right children, Count total nodes recursively
      2   3
     / \
    4   5
*/

/*#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int main() {
    // Create nodes
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Root: " << root->data << endl;
    cout << "Left Child of Root: " << root->left->data << endl;
    cout << "Right Child of Root: " << root->right->data << endl;
    return 0;
}*/

// Given the root of a binary tree, write a recursive function to find the height of the above given tree.

/*#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};
int findHeight(Node* root){
    if(root == NULL)return 0;
    int leftH = findHeight(root->left);
    int rightH = findHeight(root->right);
    return max(leftH, rightH)+1;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << "Height of Tree: " << findHeight(root);
    return 0;
}*/

