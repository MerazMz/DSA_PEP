class Solution {
public:
    int maxSum = 0;

    struct Info {
        bool isBST;
        int sum;
        int maxVal;
        int minVal;
    };

    Info dfs(TreeNode* root) {
        if (!root)
            return {true, 0, INT_MIN, INT_MAX};

        Info left = dfs(root->left);
        Info right = dfs(root->right);

        // Check if current tree is BST
        if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
            int currSum = root->val + left.sum + right.sum;
            maxSum = max(maxSum, currSum);
            return {
                true,
                currSum,
                max(root->val, right.maxVal),
                min(root->val, left.minVal)
            };
        }

        // Not a BST
        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
