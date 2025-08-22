class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxRow=INT_MIN,maxCol=INT_MIN,minRow=INT_MAX,minCol=INT_MAX;
        bool found=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    found=true;
                    minRow=min(minRow,i);
                    maxRow=max(maxRow,i);
                    minCol=min(minCol,j);
                    maxCol=max(maxCol,j);
                }
            }
        }
        if(!found) return 0;
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};