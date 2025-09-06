class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int> pq;
        for(int n:nums){
            pq.push(n);
        }
        int n1 = pq.top();
        pq.pop();
        int n2 = pq.top();
        return (n1-1)*(n2-1); 
    }
};