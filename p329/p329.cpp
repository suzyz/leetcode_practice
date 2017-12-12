class Solution {
public:
	int res, n, m;
	const int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        if (n == 0)
        	return 0;
        m = matrix[0].size();
        if (m == 0)
        	return 0;

        res = 1;
        vector<vector<int>> f(n,vector<int>(m,0));
        for (int i = 0; i < n; ++i)
        	for (int j = 0; j < m; ++j)
        	{
        		dfs(i,j,matrix,f);
        		res = max(f[i][j],res);
        		if (res == m*n)
        			break;
        	}
        
        return res;
    }

    void dfs(int x,int y,vector<vector<int>> &matrix,vector<vector<int>> &f)
    {
    	if (f[x][y] > 0)
    		return;

    	f[x][y] = 1;
    	for (int i = 0; i < 4; ++i)
    	{
    		int tx = x + dir[i][0];
    		if (tx < 0 || tx >= n)
    			continue;
    		int ty = y + dir[i][1];
    		if (ty < 0 || ty >= m || matrix[tx][ty] <= matrix[x][y])
    			continue;

    		dfs(tx,ty,matrix,f);
    		f[x][y] = max(f[x][y],f[tx][ty]+1);
    	}
    }
};
