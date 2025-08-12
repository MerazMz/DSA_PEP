/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rootVal;
    long mini = LONG_MAX;
    void dfs(TreeNode* node){
        if(!node) return;
        if(node->val > rootVal && node->val < mini){
            mini = node->val;
        }else if(node->val==rootVal){
            dfs(node->left);
            dfs(node->right);
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        rootVal = root->val;
        dfs(root);
        return (mini==LONG_MAX)? -1:mini;
    }
};