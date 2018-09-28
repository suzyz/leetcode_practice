// Dfs
class Solution {
public:

	bool isSimilar(string& a, string& b) {
		int count = 0;
		for (int i = 0; i < a.length(); ++i)
			if (a[i] != b[i]) {
				++count;

				if (count > 2)
					return false;
			}

		return true;
	}

	void dfs(int cur, vector<vector<int>>& g, vector<bool>& vis) {
		vis[cur] = true;

		for (int i = 0; i < g[cur].size(); ++i) {
			int t = g[cur][i];
			if (!vis[t])
				dfs(t, g, vis);
		}
	}

    int numSimilarGroups(vector<string>& A) {
        int n = A.size();
        vector<vector<int>> g(n);

        for (int i = 0; i < n; ++i)
        	for (int j = i+1; j < n; ++j) {
        		if (isSimilar(A[i], A[j])) {
        			g[i].push_back(j);
        			g[j].push_back(i);
        		}
        	}
        
        vector<bool> vis(n, false);

        int ans = 0;
        for (int i = 0; i < n; ++i)
        	if (!vis[i]) {
        		++ans;
        		dfs(i, g, vis);
        	}

        return ans;
    }
};