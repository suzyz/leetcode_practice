// Dijkstra with priority queue.
// O(N^2 * logN)

class Solution {
public:
    const int dir[4][2] = {{1,0}, {-1,0}, {0,1},{0,-1}};

    struct Status
    {
        int v, x, y;
        Status(int a, int b, int c) { v = a; x = b; y = c; }

        bool operator< (const Status& b) const { return v > b.v; }
    };

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n));

        priority_queue<Status> pq;
        pq.push(Status(grid[0][0], 0, 0));
        vis[0][0] = true;

        int ans = 0;
        while (!pq.empty()) {
            Status cur = pq.top();
            pq.pop();

            ans = max(ans, cur.v);
            if (cur.x == n-1 && cur.y == n-1)
                return ans;

            for (int i = 0; i < 4; ++i)
            {
                int x = cur.x + dir[i][0], y = cur.y + dir[i][1];
                if (x >= 0 && x < n && y >= 0 && y < n && !vis[x][y]) {
                    vis[x][y] = true;
                    pq.push(Status(grid[x][y], x, y));
                }
            }
        }
        
        return n*n;
    }
};