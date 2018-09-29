// Try to delete every edge that doesn't cause the "tree" to 
// have no roots or more than one root.

// O(N^2).

class Solution {
public:
    int n, removeU, removeV;
    bool vis[1002];

    int dfs(int cur, vector<vector<int>>& g) {
        if (vis[cur])
            return 0;

        vis[cur] = true;
        int sum = 1;

        for (int i = 0; i < g[cur].size(); ++i) {
            int v = g[cur][i];

            if (cur == removeU && v == removeV)
                continue;

            sum += dfs(v, g);
        }

        return sum;
    }

    bool check(vector<vector<int>>& g, vector<int>& inDegree) {
        memset(vis, 0, sizeof(vis));

        int root = -1;
        for (int i = 1; i <= n; ++i)
            if (inDegree[i] == 0) {
                if (root != -1)
                    return false;

                root = i;
                break;
            }

        if (root == -1)
            return false;
        
        return dfs(root, g) == n;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        n = edges.size();
        vector<int> inDegree(n+1, 0);
        vector<vector<int>> g(n+1);

        for (int i = 0; i < n; ++i) {
            int u = edges[i][0], v = edges[i][1];

            g[u].push_back(v);
            ++inDegree[v];
        }

        int roots = 0;
        for (int i = 1; i <= n; ++i)
            if (inDegree[i] == 0)
                ++roots;

        for (int i = n-1; i >= 0; --i) {
            int v = edges[i][1];
            if (inDegree[v] == 1 && roots > 0) // the "tree" would have more than one root
                continue;

            if (inDegree[v] > 1 && roots == 0) // the "tree" would have no roots
                continue;

            --inDegree[v];

            removeU = edges[i][0];
            removeV = v;
            if (check(g, inDegree)) {
                return edges[i];
            }

            ++inDegree[v];
        }

        return vector<int>(2, 0);
    }
};