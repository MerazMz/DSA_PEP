class Solution {
public:
    bool isVowel(char c){
        c=tolower(c);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return true;
        }
        return false;
    }
    bool doesAliceWin(string s) {
        bool ans=false;
        for(char c:s){
            if(isVowel(c)){
                ans=true;
            }
        }
        return ans;
    }
};