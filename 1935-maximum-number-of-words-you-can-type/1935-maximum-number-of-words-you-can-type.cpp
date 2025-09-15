class Solution {
public:
    bool isPresent(char c, string broken){
        for(int i=0;i<broken.size();i++){
            if(broken[i]==c){
                return false;
            }
        }
        return true;
    }
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        string word;
        int count=0;
        while (ss >> word) {
            bool ok = true;
            for(int i=0;i<word.size();i++){
                if(!isPresent(word[i],brokenLetters)){
                    ok = false;
                    break;
                }
            }
            if(ok) count++;
        }
        return count;
    }
};