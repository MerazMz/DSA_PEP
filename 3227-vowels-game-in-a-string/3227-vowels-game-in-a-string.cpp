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
        return s.find_first_of("aeiou") != string::npos;
    }
};