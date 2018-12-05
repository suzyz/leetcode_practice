// Binary Search and BFS.
// O(N^2 * logN)

class Solution {
public:
    int n;
    const int dir[4][2] = {{1,0}, {-1,0}, {0,1},{0,-1}};

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();

        int lo = grid[0][0], hi = n*n-1;
        while (lo < hi) {
            int mid = lo + ((hi-lo)>>1);
            if (bfs(mid, grid))
                hi = mid;
            else
                lo = mid+1;
        }

        return lo;
    }

    bool bfs(int lim, vector<vector<int>>& grid) {
        queue<pair<int, int>> qu;
        vector<vector<bool>> vis(n, vector<bool>(n));
        
        qu.push(make_pair(0, 0));
        vis[0][0] = true;

        int ans = 0;
        while (!qu.empty()) {
            int x = qu.front().first, y = qu.front().second;
            qu.pop();

            for (int i = 0; i < 4; ++i)
            {
                int tx = x + dir[i][0], ty = y + dir[i][1];
                if (tx >= 0 && tx < n && ty >= 0 && ty < n 
                    && !vis[tx][ty] && grid[tx][ty] <= lim) {
                    
                    if (tx == n-1 && ty == n-1)
                        return true;

                    vis[tx][ty] = true;
                    qu.push(make_pair(tx, ty));
                }
            }
        }

        return false;
    }
};