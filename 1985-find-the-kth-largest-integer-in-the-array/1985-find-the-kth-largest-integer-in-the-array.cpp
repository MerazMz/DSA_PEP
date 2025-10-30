struct compartor{
    bool operator()(string&a,string &b){
        if(a.size()!=b.size()){
            return b.size()<a.size(); 
        }   
        return b<a; 
    }
};
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) { 
        priority_queue<string,vector<string>,compartor>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k)pq.pop();
        }
        return pq.top();
    }
};