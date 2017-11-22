class Solution {
public:
	const int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

	int n = 0, m = 0;
	bool flag = false;
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        if (n == 0)
        	return false;

        m = board[0].size();
        if (m == 0)
        	return false;

        vector<vector<bool>> vis(n,vector<bool>(m,false));

        flag = false;
        for (int i = 0; i < n; ++i)
        	for (int j = 0; j < m; ++j)
        		if (board[i][j] == word[0])
        		{
        			vis[i][j] = true;
        			dfs(i,j,board,1,word,vis);
        			vis[i][j] = false;
        			if (flag)
        				return true;
        		}
        
        return false;
    }

    void dfs(int x,int y,vector<vector<char>> &board,int cur,string &word,vector<vector<bool>> &vis)
    {
    	if (cur == word.length())
    	{
    		flag = true;
    		return;
    	}

    	if (flag)
    		return;

    	for (int i = 0; i < 4; ++i)
    	{
    		int tx = x + dir[i][0];
    		if (tx < 0 || tx >= n)
    			continue;

    		int ty = y + dir[i][1];
    		if (ty < 0 || ty >= m || vis[tx][ty] || board[tx][ty] != word[cur])
    			continue;

    		vis[tx][ty] = true;
    		dfs(tx,ty,board,cur+1,word,vis);
    		if (flag)
    			return;
    		vis[tx][ty] = false;
    	}
    }
};
