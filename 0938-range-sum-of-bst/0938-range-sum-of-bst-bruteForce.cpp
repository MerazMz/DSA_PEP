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
    void inorder(TreeNode* root, vector<int>& nums){
        if(!root) return;
        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> nums;
        inorder(root,nums);
        int sum=0,st=0,end=nums.size()-1;
        while(nums[st]!=low) st++;
        while(nums[end]!=high) end--;
        for(int i=st;i<=end;i++){
            sum=sum+nums[i];
        }
        return sum;
    }
};