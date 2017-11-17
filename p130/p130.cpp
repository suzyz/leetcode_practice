class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0)
        	return;

        int m = board[0].size();
        if (m == 0)
        	return;

        vector<vector<bool>> not_surrounded(n,vector<bool>(m,false));

        for (int i = 0; i < n; ++i)
        {
        	if (board[i][0] == 'O')
        		dfs(i,0,n,m,board,not_surrounded);
        	if (board[i][m-1] == 'O')
        		dfs(i,m-1,n,m,board,not_surrounded);
        }

        for (int i = 0; i < m; ++i)
        {
        	if (board[0][i] == 'O')
        		dfs(0,i,n,m,board,not_surrounded);
        	if (board[n-1][i] == 'O')
        		dfs(n-1,i,n,m,board,not_surrounded);
        }

        for (int i = 0; i < n; ++i)
        	for (int j = 0; j < m; ++j)
        		if (board[i][j] == 'O' && !not_surrounded[i][j])
        			board[i][j] = 'X';
    }

    void dfs(int x,int y,int n,int m,vector<vector<char>>& board,vector<vector<bool>> &not_surrounded)
    {
    	if (x<0 || y<0 || x>=n || y>=m || not_surrounded[x][y] || board[x][y] != 'O')
    		return;

    	not_surrounded[x][y] = true;

    	dfs(x+1,y,n,m,board,not_surrounded);
    	dfs(x-1,y,n,m,board,not_surrounded);
    	dfs(x,y+1,n,m,board,not_surrounded);
    	dfs(x,y-1,n,m,board,not_surrounded);
    }
};
