class Solution {
public:
    int n,m;
    vector<int> fa;
    vector<vector<int>> g;
   
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        g = grid;

        n = g.size();
        m = g[0].size();

        int k = hits.size();
        vector<int> ans(k);

        for (int i = 0; i < k; ++i) {
            int x = hits[i][0], y = hits[i][1];
            if (g[x][y] == 0)
                hits[i][0] = -1;
            else
                g[x][y] = 0;
        }

        fa = vector<int>(n * m + 1, -1);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (g[i][j])
                    connect(i, j);
        
        for (int i = k-1; i >= 0; --i) {
            int x = hits[i][0], y = hits[i][1];
            if (x == -1)
                continue;

            int old = -fa[0];

            g[x][y] = 1;
            connect(x, y);

            if (-fa[0] - 1 > old)
                ans[i] = -fa[0] - 1 - old;
        }

        return ans;
    }

    void connect(int x, int y) {
        int cur = m * x + y + 1;

        if (x == 0)
            unify(0, cur);
        else
            if (x > 0 && g[x-1][y])
                unify(cur, cur - m);

        if (x < n-1 && g[x+1][y])
            unify(cur, cur + m);

        if (y > 0 && g[x][y-1])
            unify(cur, cur - 1);

        if (y < m-1 && g[x][y+1])
            unify(cur, cur + 1);
    }

    int get_fa(int cur) {
        if (fa[cur] < 0)
            return cur;

        fa[cur] = get_fa(fa[cur]);
        return fa[cur];
    }

    void unify(int a, int b) {
        int f1 = get_fa(a), f2 = get_fa(b);
        
        if (f1 != f2) {
            if (f1 == 0) {
                fa[0] += fa[f2];
                fa[f2] = 0;
            } else {
                fa[f2] += fa[f1];
                fa[f1] = f2;
            }
        }
    }
};