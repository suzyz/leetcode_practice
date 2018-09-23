class Solution {
public:

	int n, m;
	int x[402], y[402], dist[402], vis[402];
	vector<int> g[402];

	int dij() {
		memset(dist, -1, sizeof(dist));
		memset(vis, 0, sizeof(vis));

		dist[1] = 0;
		for (int i = 0; i < g[1].size(); ++i)
			dist[g[1][i]] = 1;
		
		vis[1] = true;

		for (int i = 0; i < m; ++i) {
			int k = -1, mind = INT_MAX;
			for (int j = 1; j <= m; ++j)
				if (!vis[j] && dist[j] != -1 && dist[j] < mind) {
					k = j;
					mind = dist[j];
				}
            // printf("k:%d\n",k);
//             for (int j = 1; j <= m; ++j)
//         {
        	
//         		printf("%d:%d\n",j, dist[j]);
        	
//         }
			if (k == -1)
				break;

            vis[k] = true;
			for (int j = 0; j < g[k].size(); ++j){
				int t = g[k][j];
				if (!vis[t] && (dist[t] == -1 || dist[t] > mind+1))
					dist[t] = mind + 1;
			}

		}

		return dist[m];
	}
	
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        m = n*n;

        int j = 0, id = 1, dir = 1, lastj = 0;
        for (int i = n-1; i >= 0; --i) {
        	j = lastj;
        	for (int k = 0; k < n; ++k)
        	{
        		x[id] = i;
        		y[id] = j;
        		lastj = j;
        		
        		j += dir;
        		id++;
        	}

        	dir = -dir;
        }
        	
        
        for (int i = 1; i < m; ++i)
        {
        	for (int k = 1; k <= 6; ++k)
        	{
        		int t = i + k;
        		if (t > m)
        			break;

        		if (board[x[t]][y[t]] != -1) {
        			t = board[x[t]][y[t]];
        		}

        		g[i].push_back(t);
                // printf("%d %d\n", i, t);
        	}
        }
        
//          for (int i = 1; i <= m; ++i)
//         {
        	
//         		printf("%d:%d\n",i, dist[i]);
        	
//         }

        return dij();

    }
};