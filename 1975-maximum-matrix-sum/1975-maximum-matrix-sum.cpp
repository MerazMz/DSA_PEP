class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        long long sum=0;
        int countNeg=0;
        int smallNeg = INT_MAX;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int value = matrix[i][j];
                if(value<0) countNeg++;
                sum += abs(value);
                smallNeg = min(smallNeg, abs(value)); 
            }
        }
        if(countNeg % 2 == 1) { 
            sum = sum - smallNeg; //which makes it +smallNeg to 0
            sum = sum - smallNeg; //which makes it +smallNeg to -smallNeg
        }
        return sum;
        
    }
};