#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data){
        this->data = data;
        left = right = NULL;
    }
};

TreeNode *nextRight = NULL;
void flatten(TreeNode *root){
    if (!root)
        return;

    flatten(root->right);
    flatten(root->left);
    root->left = NULL;
    root->right = nextRight;
    nextRight = root;
}

int main(){
    
}