// DP.
class Solution {
public:
    int f[12][4100];
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1)
        	return 0;

        int fullState = (1<<n) - 1;

        memset(f, -1, sizeof(f));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= fullState; ++j)
                f[i][j] = n*n;
            
            f[i][1<<i] = 0;
        }
        
        


        return steps;
    }
};