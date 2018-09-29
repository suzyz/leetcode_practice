// Union find. O(N).

// The rooted tree has exactly one added edge,
// so the new graph either has a circle or has a vertex with exactly two parents.

class Solution {
public:
    int fa[1002];

    int getfa(int cur) {
        if (fa[cur] == cur)
            return cur;

        fa[cur] = getfa(fa[cur]);
        return fa[cur];
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0);

        vector<int> candidate1;
        int candidate2Idx = -1;

        for (int i = 0; i < n; ++i) {
            int u = edges[i][0], v = edges[i][1];

            if (parent[v] == 0)
                parent[v] = u;
            else {
                candidate1 = vector<int>(2);
                candidate1[0] = parent[v];
                candidate1[1] = v;

                candidate2Idx = i;

                break;
            }
        }

        for (int i = 1; i <= n; ++i)
            fa[i] = i;
        
        for (int i = 0; i < n; ++i)
            if (i != candidate2Idx) {
                int u = edges[i][0], v = edges[i][1];
                int f1 = getfa(u);

                // now v only has one parent(u), so v's root is v
                if (f1 == v) {
                    if (candidate2Idx == -1)
                        return edges[i];
                    else
                        return candidate1;       
                }

                fa[v] = f1;
            }

        return edges[candidate2Idx];
    }
};