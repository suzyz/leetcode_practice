class Solution {
public:
	int n,m;
	const int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
    	vector<pair<int,int>> res;

    	n = matrix.size();
    	if (n == 0)
    		return res;
    	m = matrix[0].size();
    	if (m == 0)
    		return res;

        vector<vector<bool>> pacific(n,vector<bool>(m,0)),atlantic(n,vector<bool>(m,0));
        for (int i = 0; i < n; ++i)
        	pacific[i][0] = atlantic[i][m-1] = true;
        for (int i = 0; i < m; ++i)
        	pacific[0][i] = atlantic[n-1][i] = true;

        for (int i = 0; i < n; ++i)
        {
        	dfs(i,0,matrix,pacific);
        	dfs(i,m-1,matrix,atlantic);
        }

        for (int i = 0; i < m; ++i)
        {
        	dfs(0,i,matrix,pacific);
        	dfs(n-1,i,matrix,atlantic);
        }

        for (int i = 0; i < n; ++i)
        	for (int j = 0; j < m; ++j)
        		if (pacific[i][j] && atlantic[i][j])
        			res.push_back(make_pair(i,j));

        return res;
    }

    void dfs(int x,int y,vector<vector<int>>& matrix,vector<vector<bool>>& ocean)
    {
    	ocean[x][y] = true;

    	for (int i = 0; i < 4; ++i)
    	{
    		int tx = x + dir[i][0];
    		if (tx < 0 || tx >= n)
    			continue;

    		int ty = y + dir[i][1];
    		if (ty < 0 || ty >= m || matrix[tx][ty] < matrix[x][y] || ocean[tx][ty])
    			continue;

    		dfs(tx,ty,matrix,ocean);
    	}
    }
};
