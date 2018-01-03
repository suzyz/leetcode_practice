class Solution {
public:
	const int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0)
        	return 0;

        int m = grid[0].size(), res = 0;
        for (int i = 0; i < n; ++i)
        	for (int j = 0; j < m; ++j)
        		if (grid[i][j] == 1)
        		{
        			for (int k = 0; k < 4; ++k)
        			{
        				int x = i + dir[k][0];
        				int y = j + dir[k][1];
        				if (x < 0 || x == n || y < 0 || y == m)
        					++res;
        				else
        				if (grid[x][y] == 0)
        					++res;
        			}
        		}

        return res;
    }
};
