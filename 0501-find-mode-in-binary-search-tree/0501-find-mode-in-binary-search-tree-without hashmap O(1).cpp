class Solution {
public:
    vector<int> ans;
    int maxCount = 0;
    int count = 0;
    TreeNode* prev = NULL;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        
        if (prev != NULL && prev->val == root->val) {
            count++;
        } else {
            count = 1;
        }

        if (count == maxCount) {
            ans.push_back(root->val);
        } else if (count > maxCount) {
            ans.clear();
            ans.push_back(root->val);
            maxCount = count;
        }
        prev = root;

        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};
