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
    TreeNode* helper(TreeNode* root, int &sum){
        
        if(root==NULL) return NULL;

        helper(root->right,sum);
        sum = sum+root->val;
        root->val=sum;
        helper(root->left,sum);
        return root;
    };

    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        helper(root,sum);

        if(root==NULL) return NULL;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        return root;

    }
};