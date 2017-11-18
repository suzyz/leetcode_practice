class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0)
        	return;

        int m = board[0].size();
        if (m == 0)
        	return;

        for (int i = 0; i < n; ++i)
        {
        	dfs(i,0,n,m,board);
        	dfs(i,m-1,n,m,board);
        }

        for (int i = 0; i < m; ++i)
        {
        	dfs(0,i,n,m,board);
        	dfs(n-1,i,n,m,board);
        }

        for (int i = 0; i < n; ++i)
        	for (int j = 0; j < m; ++j)
        		if (board[i][j] == 'O')
        			board[i][j] = 'X';
                else
                if (board[i][j] == 'A')
                    board[i][j] = 'O';
    }

    void dfs(int x,int y,int n,int m,vector<vector<char>>& board)
    {
    	if (board[x][y] == 'O')
        {
            board[x][y] = 'A';
            if (x<n-1)
                dfs(x+1,y,n,m,board);
            if (x>0)
                dfs(x-1,y,n,m,board);
            if (y<m-1)
                dfs(x,y+1,n,m,board);
            if (y>0)
               dfs(x,y-1,n,m,board); 
        }
    }
};
