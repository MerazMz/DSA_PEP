class Solution {
public:
    int maximumSwap(int num) {
        string digi = to_string(num);
        vector<int> pos(10,-1);
        for(int i=0;i<digi.size();i++){
            pos[digi[i]-'0']=i;
        }

        for (int i = 0; i < digi.size(); i++) {
            for (int d = 9; d > digi[i] - '0'; d--) {
                if (pos[d] > i) {
                    swap(digi[i], digi[pos[d]]);
                    return stoi(digi);
                }
            }
        }
        return num;

    }
};