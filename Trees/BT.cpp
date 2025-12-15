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
};

static int idx = -1;
Node* buildTree(vector<int> &preOrder) {
    idx++;
    if (idx >= preOrder.size() || preOrder[idx] == -1) {
        return NULL;
    }

    Node* newNode = new Node(preOrder[idx]);
    newNode->left = buildTree(preOrder);
    newNode->right = buildTree(preOrder);
    
    return newNode;
}

int main() {
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    
    Node* root = buildTree(preOrder);
    if (root) cout << "Root: " << root->data << endl;            
    if (root->left) cout << "Left: " << root->left->data << endl;   
    if (root->right) cout << "Right: " << root->right->data << endl; 
    
    return 0;
}