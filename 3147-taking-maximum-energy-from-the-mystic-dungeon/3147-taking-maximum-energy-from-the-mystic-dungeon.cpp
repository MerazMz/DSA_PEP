class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> res(n);
        int ans = INT_MIN;

        for (int i = n - 1; i >= 0; i--) {
            res[i] = energy[i] + ((i + k < n) ? res[i + k] : 0);
            ans = max(ans, res[i]);
        }
        return ans;
    }
};