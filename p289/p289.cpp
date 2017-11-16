class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        if (n == 0)
        	return;
        int m = board[0].size();
        const int dir[][2] = {{0,1},{0,-1},{1,0},{-1,0},
    						{1,1},{1,-1},{-1,1},{-1,-1}};

        for (int i = 0; i < n; ++i)
        	for (int j = 0; j < m; ++j)
        	{
        		int sum = 0;
        		for (int k = 0; k < 8; ++k)
        		{
        			int x = i + dir[k][0], y = j + dir[k][1];
        			if (x < 0 || y < 0 || x >= n || y >= m)
        				continue;

        			sum += (board[x][y]&1);
        		}

        		if ((board[i][j] && (sum == 2 || sum == 3)) || (!board[i][j] && sum == 3))
        				board[i][j] |= (1<<1);
        	}
        
        for (int i = 0; i < n; ++i)
        	for (int j = 0; j < m; ++j)
        		board[i][j] >>= 1;
    }
};
