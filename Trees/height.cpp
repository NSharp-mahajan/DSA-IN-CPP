#include<iostream>
#include<vector>
#include<algorithm> // Required for max()
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
int height(Node* root){
    if(root == NULL){
        return 0; 
    }
    int leftHeight = height(root->left); 
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int main(){
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preOrder);
    cout << "Height: " << height(root) << endl;
    return 0;
}