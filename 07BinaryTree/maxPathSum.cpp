#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        left = right = NULL;
    }
}; 
int maxPathDown(TreeNode *root, int &maxi){
    if (root == NULL)
        return 0;

    int leftSum = maxPathDown(root->left, maxi);
    int rightSum = maxPathDown(root->right, maxi);

    if (leftSum < 0)
        leftSum = 0;
    if (rightSum < 0)
        rightSum = 0;

    maxi = max(maxi, leftSum + rightSum + root->val);

    return root->val + max(leftSum, rightSum);
}

int maxPathSum(TreeNode *root)
{
    int maxi = INT_MIN;
    maxPathDown(root, maxi);
    return maxi;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout << maxPathSum(root) << endl;
}