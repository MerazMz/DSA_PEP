class Solution {
public:
    bool nozero(int n){
        int temp = n;
        while(temp>0){
            int ld=temp%10;
            if(ld==0) return false;
            temp=temp/10;
        }
        return true;
    }
    
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++){
            int a=i,b=n-i;
            if(nozero(a) && nozero(b)){
                return{a,b};
            }
        }
        return{};
    }
};