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
    vector<int> merge(vector<int>& v1, vector<int>& v2) {
        vector<int> res;
        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size()) {
            if (v1[i] < v2[j]) res.push_back(v1[i++]);
            else res.push_back(v2[j++]);
        }
        while (i < v1.size()) res.push_back(v1[i++]);
        while (j < v2.size()) res.push_back(v2[j++]);
        return res;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> r1;
        vector<int> r2;
        inorder(root1,r1);
        inorder(root2,r2);
        return merge(r1,r2);
    }
};