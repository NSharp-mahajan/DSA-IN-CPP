#include<iostream>
#include<vector>
using namespace std;

class Node {
public: 
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; // FIX 1: Added missing semicolon

Node* insert(Node* root, int val) {
    if(root == NULL) {
        return new Node(val);
    }
    
    if(val < root->data) {
        root->left = insert(root->left, val);
    } else {
        // FIX 2: Corrected function call syntax
        root->right = insert(root->right, val);
    }
    return root;
}

Node* buildBST(vector<int> arr) {
    Node* root = NULL;
    for(int val : arr) {
        root = insert(root, val);
    }
    return root;
}

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool search(Node* root, int key){
    if(root == NULL){
        return false;
    }
    if(root->data==key){
        return true;
    }
    if(key < root->data){
        return search(root->left,key);
    }else{
        return search(root->right,key);
    }
}

int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node* root = buildBST(arr);
   
    cout << search(root, 5) << endl;
    
    /*cout << "Inorder Traversal (Sorted): ";
    inorder(root);
    cout << endl;*/
    
    return 0;
}