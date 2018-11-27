class Solution {
public:
	int n,m;
    queue<pair<int, int>> qu;
    vector<unordered_set<pair<int, int>>> s;

    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        n = grid.size();
        m = grid[0].size();

        drop(grid);

        vector<int> ans;
        for (int i = 0; i < hits.size(); ++i) {
        	int x = hits[i][0], y = hits[i][1];
        	if (!grid[x][y])
        		ans.push_back(0);
        	else {
        		grid[x][y] = 0;
        		ans.push_back(drop(grid));
        	}
        }

        return ans;
    }

    int drop(vector<vector<int>>& grid) {
    	vector<vector<bool>> vis(n, vector<bool>(m));

        for (int i = 0; i < m; ++i)
        	if (grid[0][i] && !vis[0][i])
        		qu.push(make_pair(0, i));

        int count = 0;
        for (int i = 0; i < n; ++i)
        	for (int j = 0; j < m; ++j)
        		if (grid[i][j] && !vis[i][j]) {
        			++count;
        			grid[i][j] = 0;
        		}

        return count;
    }	
};