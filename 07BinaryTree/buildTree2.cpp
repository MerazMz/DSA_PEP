#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode{ //tree structure
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left=right=NULL;
    }
};
int search(vector<int>& inorder,int left, int right, int val){ //search for the value in the inorder vector
    for(int i=left;i<=right;i++){
        if(inorder[i]==val) return i;
    }
    return -1;
}

TreeNode* BT(vector<int>& inorder,vector<int>& preorder, int& idx,int left,int right){ //build the tree
    if(left>right) return NULL;

    TreeNode* root = new TreeNode(preorder[idx]);

    int inIdx = search(inorder,left,right,preorder[idx]);
    idx++;

    root->left=BT(inorder,preorder,idx,left,inIdx-1);
    root->right=BT(inorder,preorder,idx,inIdx+1,right);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder){ //build the tree function
    int idx=0;
    return BT(inorder,preorder,idx,0,inorder.size()-1);
}


int main(){
    vector<int> inorder = {9,3,15,20,7};
    vector<int> preorder = {3,9,20,15,7};
    TreeNode* root = buildTree(inorder, preorder);

    // LeetCode style: level order traversal, print nulls for missing children
    vector<string> output;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            output.push_back(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        } else {
            output.push_back("null");
        }
    }
    // Remove trailing "null"s
    while (!output.empty() && output.back() == "null") output.pop_back();

    cout << "[";
    for (size_t i = 0; i < output.size(); ++i) {
        if (i) cout << ",";
        cout << output[i];
    }
    cout << "]" << endl;

    return 0;
}
