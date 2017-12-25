class Solution {
public:
	int n,m,res = 0, cur_size = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        if (n == 0)
        	return 0;
        m = grid[0].size();
        if (m == 0)
        	return 0;

        for (int i = 0; i < n; ++i)
        	for (int j = 0; j < m; ++j)
        		if (grid[i][j] == 1)
        		{
        			cur_size = 0;
        		    dfs(i,j,grid);
        		    res = max(res,cur_size);
        		}

        return res;
    }

    void dfs(int x,int y,vector<vector<int>>& grid)
    {
    	if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] != 1)
    		return;

    	++cur_size;
    	grid[x][y] = 0;

    	dfs(x+1,y,grid);
    	dfs(x,y+1,grid);
    	dfs(x-1,y,grid);
    	dfs(x,y-1,grid);
    }
};
