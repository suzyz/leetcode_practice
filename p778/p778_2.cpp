// Build a graph and "Dijkstra".

class Solution {
public:
    int n, square, tot;
    unordered_map<int, vector<pair<int, int>>> g;

    struct mycmp
    {
        bool operator() (pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        }
    };

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

        vector<int> dist(tot, square);
        dist[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
            mycmp> pq;

        pq.push(make_pair(0, 0));

        while (!pq.empty()) {
            int u = pq.top().first, d = pq.top().second;
            pq.pop();

            if (d > dist[u])
                continue;

            for (int i = 0; i < g[u].size(); ++i) {
                int v = g[u][i].first, w = max(g[u][i].second, d);

                if (dist[v] > w) {
                    dist[v] = w;
                    pq.push(make_pair(v, w));
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