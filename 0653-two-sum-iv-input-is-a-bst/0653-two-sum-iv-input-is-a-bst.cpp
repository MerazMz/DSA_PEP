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
        if(root==NULL) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root,nums);
        int st=0,end=nums.size()-1;
        while(st<end){
        int ans=nums[st]+nums[end];
            if(ans==k){
                return true;
            }else if(ans<k){
                st++;
            }else{
                end--;
            }
        }
        return false;
    }
};


//  2 3 4 5 6 9    k=9