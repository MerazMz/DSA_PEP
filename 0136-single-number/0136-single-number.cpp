class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int pos=0;
        while(pos<n-1){
            if(nums[pos]==nums[pos+1]){
                pos=pos+2;
            }else{
                return nums[pos];
            }
        }
        return nums[n-1];
        
    }
};