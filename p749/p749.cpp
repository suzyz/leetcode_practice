class Solution {
public:
	int n, m, ans, tot;
	vector<vector<int>> walls;
	const int dir[4][2] = {{1,0}, {0,1}, {0,-1}, {-1,0}};

    int containVirus(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        walls = vector<vector<int>>(n, vector<int>(m));

        ans = 0;
        while (true) {
            tot = 0;
        	int maxThreat = 0, idx = 0, sx, sy;
        	vector<vector<int>> co(n, vector<int>(m));

        	for (int i = 0; i < n; ++i)
        		for (int j = 0; j < m; ++j)
        			if (grid[i][j] && !co[i][j]) {
        				++tot;
        				vector<vector<bool>> vis(n, vector<bool>(m));

        				int cur = dfs(i, j, vis, co, grid);
        				if (cur > maxThreat) {
        					maxThreat = cur;
        					idx = tot;

        					sx = i;
        					sy = j;
        				}
                        
                        // printf("tot:%d\n", tot);
                        // for (int k = 0; k<n; ++k){
                        //     for (int p = 0; p < m; ++p)
                        //         printf("%d ", (int)vis[k][p]);
                        //     printf("\n");
                        // }
        			}
            
            // for (int i = 0; i < n; ++i) {
            //     for (int j = 0; j < m; ++j)
            //         printf("%d ", co[i][j]);
            //     printf("\n");
            // }
            
            // printf("maxThreat:%d idx:%d\n", maxThreat, idx);

        	if (maxThreat == 0)
        		break;

            vector<vector<bool>> vis(n, vector<bool>(m));
        	buildWall(sx, sy, idx, vis, co);
            
            // printf("built %d\n", ans);

        	for (int i = 0; i < n; ++i)
        		for (int j = 0; j < m; ++j)
        			if (co[i][j] == idx)
        				grid[i][j] = 0;

        	co = grid;
        	for (int i = 0; i < n; ++i)
        		for (int j = 0; j < m; ++j)
        			if (co[i][j]) {
        				for (int k = 0; k < 4; ++k)
        					if ((walls[i][j]&(1<<k)) == 0) {
        						int tx = i + dir[k][0];
        						if (tx < 0 || tx >= n)
        							continue;
        						int ty = j + dir[k][1];
        						if (ty < 0 || ty >= m)
        							continue;

        						grid[tx][ty] = 1;
        					}
        			}
        }

        return ans;
    }

    int dfs(int x, int y, vector<vector<bool>>& vis, vector<vector<int>>& co, vector<vector<int>>& grid) {
    	co[x][y] = tot;

    	int res = 0;
    	for (int k = 0; k < 4; ++k)
    		if ((walls[x][y]&(1<<k)) == 0) {
        		int tx = x + dir[k][0];
        		if (tx < 0 || tx >= n)
        			continue;
        		int ty = y + dir[k][1];
        		if (ty < 0 || ty >= m || co[tx][ty])
        			continue;

        		if (grid[tx][ty])
        			res += dfs(tx, ty, vis, co, grid);
        		else if (!vis[tx][ty]) {
        			vis[tx][ty] = true;
        			++res;
        		}
        	}

        return res;
    }

    void buildWall(int x, int y, int idx, vector<vector<bool>>& vis, vector<vector<int>>& co) {
        vis[x][y] = true;
        
    	for (int k = 0; k < 4; ++k)
    		if ((walls[x][y]&(1<<k)) == 0) {
        		int tx = x + dir[k][0];
        		if (tx < 0 || tx >= n)
        			continue;
        		int ty = y + dir[k][1];
        		if (ty < 0 || ty >= m || vis[tx][ty])
        			continue;

        		if (co[tx][ty] == idx)
        			buildWall(tx, ty, idx, vis, co);
        		else if ((walls[x][y]&(1<<k)) == 0) {
        			++ans;
        			
        			walls[x][y] |= (1<<k);
        			walls[tx][ty] |= (1<<(3-k));
        		}
        	}
    }
};