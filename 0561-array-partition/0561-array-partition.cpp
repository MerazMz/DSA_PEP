class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        vector<pair<int,int>> pair;
        int n=nums.size();
        int sum=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i=i+2){
            pair.push_back({nums[i],nums[i+1]});
        }
        for(int i=0;i<pair.size();i++){
            sum=sum+ min(pair[i].first,pair[i].second);
        }
        return sum;
    }
};