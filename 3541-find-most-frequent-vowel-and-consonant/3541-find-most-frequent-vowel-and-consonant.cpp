class Solution {
public:
    bool isvowel(char c){
        c=tolower(c);
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    int maxFreqSum(string s) {
        unordered_map<char, int> vowel;
        unordered_map<char, int> conso;
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i])){
                vowel[s[i]]++;
            }else{
                conso[s[i]]++;
            }
        }
        int maxV=0,maxC=0;
        for(auto pair:vowel){
            maxV=max(maxV,pair.second);
        }
        for(auto pair:conso){
            maxC=max(maxC,pair.second);
        }
        return maxV+maxC;

    }
};