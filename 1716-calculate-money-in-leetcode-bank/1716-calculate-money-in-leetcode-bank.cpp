class Solution {
public:
    int totalMoney(int n) {
        int week = n / 7;
        int days = n % 7;
        int ans = 0;
        ans = week*(2*28+(week-1)*7) / 2;
        for (int i = 0; i < days; i++) {
            ans = ans+week+1+i;
        }
        return ans;
    }
};
