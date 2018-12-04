// Build a graph and bfs.

class Solution {
public:
    int n, square, tot;
    vector<int> dist;
    unordered_map<int, vector<pair<int, int>>> g;

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        square = n * n;
        tot = square << 1;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                int idx = i * n + j;
                g[idx].push_back(make_pair(idx + square, grid[i][j]));

                if (i < n-1)
                    addEdge(i, j, i+1, j);
                if (j < n-1)
                    addEdge(i, j, i, j+1);
            }

        dist = vector<int>(tot, square);
        dist[0] = 0;

        queue<int> qu;
        qu.push(0);

        while (!qu.empty()) {
            int cur = qu.front();
            qu.pop();

            for (int i = 0; i < g[cur].size(); ++i) {
                int v = g[cur][i].first, w = max(g[cur][i].second, dist[cur]);

                if (dist[v] > w) {
                    dist[v] = w;
                    qu.push(v);
                }
            }
        }

        return dist[tot-1];
    }

    void addEdge(int x1, int y1, int x2, int y2) {
        int idx1 = x1 * n + y1, idx2 = x2 * n + y2;

        g[idx1 + square].push_back(make_pair(idx2, 0));
        g[idx2 + square].push_back(make_pair(idx1, 0));
    }
};