class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int currS=0;
        int maxS=INT_MIN;
        for(int i=0;i<n;i++){
            currS += nums[i];
            maxS=max(maxS, currS);
            if(currS<0) currS=0;
        }
        return maxS;
    }
};