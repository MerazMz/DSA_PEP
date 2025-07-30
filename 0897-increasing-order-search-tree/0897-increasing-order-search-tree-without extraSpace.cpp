class Solution {
public:
    TreeNode* curr;

    void inorder(TreeNode* node) {
        if (!node) return;

        inorder(node->left);
        node->left = NULL;
        curr->right = node;
        curr = node;

        inorder(node->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(); 
        curr = dummy;
        inorder(root);
        return dummy->right; //like a linked list
    }
};
