class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0)
        	return 0;
        int m = grid[0].size();
        if (m == 0)
        	return 0;

        int f[2][m];

        f[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i)
        	f[0][i] = f[0][i-1] + grid[0][i];
        
        int flag = 1;
        for (int i = 1; i < n; ++i)
        {
        	f[flag][0] = f[1-flag][0] + grid[i][0];
        	for (int j = 1; j < m; ++j)
        		f[flag][j] = min(f[flag][j-1], f[1-flag][j]) + grid[i][j];

        	flag = 1-flag;
        }
        return f[1-flag][m-1];
    }
};
