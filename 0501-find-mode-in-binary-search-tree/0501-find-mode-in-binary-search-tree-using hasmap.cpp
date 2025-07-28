class Solution {
public:
    unordered_map<int, int> freq;
    int maxFreq = 0;

    void dfs(TreeNode* root) {
        if (!root) return;

        freq[root->val]++;
        maxFreq = max(maxFreq, freq[root->val]);

        dfs(root->left);
        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        dfs(root);

        vector<int> ans;
        for (auto& [val, f] : freq) {
            if (f == maxFreq) {
                ans.push_back(val);
            }
        }
        return ans;
    }
};
