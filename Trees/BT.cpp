/*#include<iostream>
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

void printPreOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " " << endl;
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printInOrder(Node* root){
    if(root == NULL){
        return;
    }
    printInOrder(root -> left);
    cout << root->data << " " ;
    printInOrder(root->right);
}

void printPostOrder(Node* root){
    if(root == NULL){
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

int main() {
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    
    Node* root = buildTree(preOrder);
    printPreOrder(root);
    cout << endl;
    printInOrder(root);
    cout << endl;
    printPostOrder(root);
    cout << endl;
    
    return 0;
}*/

// level order

#include <iostream>
#include <vector>
#include <queue> // Required for Level-Order
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

void levelOrder(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";
        if (curr->left != NULL) {
            q.push(curr->left);
        }
        if (curr->right != NULL) {
            q.push(curr->right);
        }
    }
}

static int idx = -1;
Node* buildTree(vector<int> &preOrder) {
    idx++;
    if (idx >= preOrder.size() || preOrder[idx] == -1) return NULL;

    Node* newNode = new Node(preOrder[idx]);
    newNode->left = buildTree(preOrder);
    newNode->right = buildTree(preOrder);
    return newNode;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    cout << "Level Order Traversal: " << endl;
    levelOrder(root);
    cout << endl;

    return 0;
}