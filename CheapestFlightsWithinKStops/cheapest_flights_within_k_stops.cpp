class Solution {
public:
	int f[102][102];
	vector<pair<int, int>> graph[102];
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if (src == dst)
        	return 0;

        for (int i = 0; i < flights.size(); ++i)
        {
        	int u = flights[i][0], v = flights[i][1], w = flights[i][2];
        	graph[u].push_back(make_pair(v, w));
        }

        memset(f, -1, sizeof(f));

        int ans = -1;
        f[0][src] = 0;

        for (int i = 0; i < K+1; ++i)
        {
        	for (int j = 0; j < n; ++j)
	        	if (f[i][j] != -1)
	        		for (int t = 0; t < graph[j].size(); ++t)
	        		{
	        			int v = graph[j][t].first;
	        			int w = graph[j][t].second;

	        			int d = f[i][j] + w;
	        			if (f[i+1][v] == -1 || f[i+1][v] > d)
	        				f[i+1][v] = d;
	        		}
	        
	        if (f[i+1][dst] != -1)  // f[i+1][dst] must be legit
		        if (ans == -1 || f[i+1][dst] < ans)
		        	ans = f[i+1][dst];
        }

        return ans;
    }
};