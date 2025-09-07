class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        for(int i=0;i<n-1;i++){
            prices[i]=prices[i+1]-prices[i];
        }
        prices[n-1]=0;
        int currSum=0,maxSum=INT_MIN;
        for(int i=0;i<n;i++){
            currSum += prices[i];
            maxSum = max(maxSum,currSum);
            if(currSum<0) currSum=0;
        }
        if(maxSum>0) return maxSum;
        return 0; 
    }
};