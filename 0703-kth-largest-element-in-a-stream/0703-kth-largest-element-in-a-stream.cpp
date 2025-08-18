class KthLargest {
public:
    int num;
    priority_queue<int, vector<int>, greater<int>> pq;

    int add(int val) {
        pq.push(val);
        if(pq.size() > num) pq.pop();
        return pq.top();
    }

    KthLargest(int k, vector<int>& nums) {
        num = k; 
        for(auto n : nums) {
            pq.push(n);
            if(pq.size() > k) 
            pq.pop();
        }
    }
    
};