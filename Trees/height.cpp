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

int count(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftCount = count(root->left);
    int rightCount = count(root->right);
    return leftCount + rightCount +1;
}

int sum(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftSum = sum(root->left);
    int rightSum = sum(root->right);
    return leftSum + rightSum + root->data;
}

int main(){
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preOrder);
    // cout << "Height: " << height(root) << endl;
    // cout << "Count: " << count(root) << endl;
    cout << "sum: "<< sum(root) << endl;
    return 0;
}