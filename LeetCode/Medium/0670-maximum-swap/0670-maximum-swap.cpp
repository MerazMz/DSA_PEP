class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        //   maxi    index  
        vector<pair<int,    int>> p(s.size());
        
            int maxi=-1;
            int maxiIdx=-1;
        for(int i=s.size()-1;i>=0;i--){ //right to left
            if(maxi<s[i]-'0'){
                maxi=s[i]-'0';
                maxiIdx=i;
            }
            p[i]={maxi,maxiIdx};
        }

        for(int i=0;i<s.size();i++){  //left to right
            if(s[i]-'0'<p[i].first){
                swap(s[i],s[p[i].second]);
                return stoi(s);
            }
        }
        return num;
    }
};