class Solution {
public:
    int sum(int x){
        int sum=0;
        while(x){
            sum = sum +x%10;
            x=x/10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
     unordered_map<int, int> freq;
     int count=0,maxi=0;
     for(int i=1;i<=n;i++){
        int digitSum=sum(i);
        maxi = max(maxi,++freq[digitSum]);
     }
     for(auto& pair:freq){
        if(pair.second==maxi){
            count++;
        }
     }   
     return count;
    }
};