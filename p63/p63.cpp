class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if (n == 0)
        	return 0;
        int m = obstacleGrid[0].size();
        if (m == 0 || obstacleGrid[0][0] == 1)
        	return 0;

        vector<int> f(m,0);
        for (int i = 0; i < m; ++i)
        	if (obstacleGrid[0][i] == 0)
        		f[i] = 1;
        	else
        		break;
        
        for (int i = 1; i < n; ++i)
        {
        	for (int j = 0; j < m; ++j)
        		if (obstacleGrid[i][j] == 0)
        			f[j] += f[j-1];
        		else
        			f[j] = 0;
        }
        
        return f[m-1];
    }
};
