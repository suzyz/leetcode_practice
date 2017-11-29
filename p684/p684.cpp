class Solution {
public:
    vector<int> fa;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        fa = vector<int>(n+2,-1);

        for (int i = 0; i < n; ++i)
        {
            int x = edges[i][0], y = edges[i][1];
            int fx = get_fa(x), fy = get_fa(y);
            if (fx == fy)
                return edges[i];
            union_two(fx,fy);
        }
        return edges[0];
    }
    int get_fa(int cur)
    {
        if (fa[cur] < 0)
            return cur;
        
        int f = cur;
        while (fa[f] > 0)
            f = fa[f];
        
        while (cur != f)
        {
            int tmp = fa[cur];
            fa[cur] = f;
            cur = tmp;
        }

        return f;
    }

    void union_two(int x,int y)
    {
        if (fa[x] < fa[y])
        {
            fa[x] += fa[y];
            fa[y] = x;
        }
        else
        {
            fa[y] += fa[x];
            fa[x] = y;
        }
    }
};
