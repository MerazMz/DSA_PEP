class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (auto &row : grid) {
            sort(row.begin(), row.end()); // sort the rows
        }
        int n = grid.size(); 
        int m = grid[0].size();   
        int score = 0;
        for (int col = 0; col < m; col++) {
            int maxi = 0;
            for (int row = 0; row < n; row++) {
                maxi = max(maxi, grid[row][col]);
            }
            score += maxi; 
        }
        return score;
    }
};
