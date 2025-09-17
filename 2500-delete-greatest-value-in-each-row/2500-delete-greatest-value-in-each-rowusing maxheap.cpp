class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<priority_queue<int>> heaps(n);
        for (int i = 0; i < n; i++) {
            for (int val : grid[i]) {
                heaps[i].push(val);
            }
        }
        int score = 0;
        for (int j = 0; j < m; j++) {
            int currentMax = 0;
            for (int i = 0; i < n; i++) {
                int topVal = heaps[i].top();
                heaps[i].pop();
                currentMax = max(currentMax, topVal);
            }
            score += currentMax;
        }
        return score;
    }
};
