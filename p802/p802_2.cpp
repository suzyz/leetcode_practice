// DP.

class Solution {
public:

    bool dfs(int cur, vector<int>& f, vector<vector<int>>& graph) {
        if (f[cur] != 0)
            return f[cur] == 1;

        f[cur] = -1;
        for (int i = 0; i < graph[cur].size(); ++i) {
            int v = graph[cur][i];

            if (!dfs(v, f, graph)) {
                return false;
            }
        }

        f[cur] = 1;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> f(n, 0);
        vector<int> ans;

        for (int i = 0; i < n; ++i)
            if (dfs(i, f, graph))
                ans.push_back(i);

        return ans;
    }
};