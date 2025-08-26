class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        int n = d.size();
        int ans = 0;
        int area = 0;  
        for(int i = 0; i < n; i++) {
            int dia = d[i][0]*d[i][0] + d[i][1]*d[i][1];
            int curArea = d[i][0]*d[i][1];
            if(dia > ans || (dia == ans && curArea > area)) {
                ans = dia;
                area = curArea;
            }
        }
        return area;
    }
};
