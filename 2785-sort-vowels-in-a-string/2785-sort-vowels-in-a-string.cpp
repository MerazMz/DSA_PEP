class Solution {
public:
    bool isVowel(char c){
        c = tolower(c);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return true;
        }
        return false;
    }
    string sortVowels(string s) {
        vector<char> vol;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                vol.push_back(s[i]);
            }
        }
        int count=0;
        sort(vol.begin(),vol.end());
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                s[i]=vol[count++];
            }
        }
        return s;
    }
};