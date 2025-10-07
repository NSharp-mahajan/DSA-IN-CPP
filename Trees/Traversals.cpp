// Given the root of a binary tree return its inorder, preorder and postorder traversal 
// root = [1, null, 2, 3]

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

// ----------------Inorder Traversal------------------------//

/*void inorder(TreeNode* root, vector<int>&ans){
    if(root == NULL) return;
    inorder(root -> left, ans);
    ans.push_back(root -> val);
    inorder(root -> right, ans); 
};
vector<int>inorderTraversal(TreeNode* root){
    vector<int>ans;
    inorder(root, ans);
    return ans;
};

int main(){
     TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}
*/

// -----------------PreOrder Traversal-----------------//

/*void preorder(TreeNode* root, vector<int>&ans){
    if(root == NULL) return;
    ans.push_back(root -> val);
    preorder(root -> left, ans);
    preorder(root -> right, ans); 
};
vector<int>preorderTraversal(TreeNode* root){
    vector<int>ans;
    preorder(root, ans);
    return ans;
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = preorderTraversal(root);

    cout << "preorder Traversal: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}*/

// ------------------Post Order Traversal----------------------//

void postorder(TreeNode* root, vector<int>&ans){
    if(root == NULL) return;
    postorder(root -> left, ans);
    postorder(root -> right, ans); 
    ans.push_back(root -> val);
};
vector<int>preorderTraversal(TreeNode* root){
    vector<int>ans;
    postorder(root, ans);
    return ans;
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = preorderTraversal(root);

    cout << "preorder Traversal: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}