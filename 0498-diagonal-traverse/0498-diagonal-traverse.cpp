class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> result;

        // total diagonals = m + n - 1
        for (int d = 0; d < m + n - 1; d++) {
            vector<int> diagonal;

            // Row starts at max(0, d - (n-1))
            int r = max(0, d - (n - 1));
            // Col starts at d - r
            int c = d - r;

            // Collect all elements in this diagonal
            while (r < m && c >= 0) {
                diagonal.push_back(mat[r][c]);
                r++;
                c--;
            }
            // For even diagonals, reverse
            if (d % 2 == 0) {
                reverse(diagonal.begin(), diagonal.end());
            }
            // Append to result
            result.insert(result.end(), diagonal.begin(), diagonal.end());
        }

        return result; 
    }
};