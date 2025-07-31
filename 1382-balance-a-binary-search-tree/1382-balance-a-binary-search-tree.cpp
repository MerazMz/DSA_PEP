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
    TreeNode* buildTree(vector<int>& nums, int st, int end){
        if (st > end) return nullptr;
        int mid = st + (end - st) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = buildTree(nums, st, mid - 1);
        node->right = buildTree(nums, mid + 1, end);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        inorder(root,nums);
        return buildTree(nums,0,nums.size()-1);
        
        
    }
};
//1 2 3 4 5 6 7 