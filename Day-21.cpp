class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int res = 0;
        int m = matrix.size();
        if(m==0) return 0;    
        int n = matrix[0].size();
        
        vector<vector<int> > DP(m+1, vector<int>(n+1, 0));
        
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++)
            {
                if(matrix[i-1][j-1]==0)
                    DP[i][j] = 0;
                else
                    DP[i][j] = 1 + min(DP[i][j-1], min(DP[i-1][j], DP[i-1][j-1]));
                res = res + DP[i][j];
            }
        return res;
    }
};
