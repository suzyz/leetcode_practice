// DP.
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n < 3)
            return n-1;

        int finalStatus = (1<<n)-1;
        vector<vector<int>> f(n, vector<int>(finalStatus+1, -1));
        
        queue<pair<int, int>> qu;
        for (int i = 0; i < n; ++i) {
            f[i][1<<i] = 0;
            qu.push(make_pair(i, 1<<i));
        }

        while (!qu.empty()) {
            int u = qu.front().first;
            int status = qu.front().second;

            qu.pop();

            for (int i = 0; i < graph[u].size(); ++i) {
                int v = graph[u][i];
                int newStatus = status | (1 << v);

                if (f[v][newStatus] == -1 || f[v][newStatus] > f[u][status] + 1) {
                    f[v][newStatus] = f[u][status] + 1;
                    qu.push(make_pair(v, newStatus));
                }
            }
        }

        int ans = n << 1;
        for (int i = 0; i < n; ++i)
            if (f[i][finalStatus] >= 0)
                ans = min(ans, f[i][finalStatus]);

        return ans;
    }
};