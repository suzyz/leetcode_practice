// DFS.
class Solution {
public:
	string ans;
	vector<string> s;
	unordered_map<string, int> idx;
	unordered_map<int, vector<int>> g;

    string crackSafe(int n, int k) {
    	if (n == 1) {
    		for (int i = 0; i < k; ++i)
    			ans += (char)('0' + i);
    		return ans;
    	}

        dfs1(0, n, k, "");

        int tot = s.size();
        for (int i = 0; i < tot; ++i)
        	for (int j = 0; j < tot; ++j)
        		if (i != j) {
        			bool ok = true;
        			for (int p = 0; p < n-1; ++p)
        				if (s[i][p+1] != s[j][p]) {
        					ok = false;
        					break;
        				}

        			if (ok)
        				g[i].push_back(j);
        		}

        vector<bool> vis(tot);
        vector<int> plan(tot);
        plan[0] = 0;
        vis[0] = true;

        dfs2(0, 1, tot, vis, plan);

        return ans;
    }

    void dfs1(int i, int n, int k, string cur) {
    	if (i == n) {
    		s.push_back(cur);
    		idx[cur] = s.size();
    		return;
    	}

    	for (int j = 0; j < k; ++j)
    		dfs1(i+1, n, k, cur + (char)('0'+j));
    }

    bool dfs2(int last, int count, int tot, vector<bool>& vis, vector<int>& plan) {
    	if (count == tot) {
    		int n = s[0].length();

    		ans = s[0];
    		for (int i = 1; i < tot; ++i)
    			ans += s[plan[i]][n-1];

    		return true;
    	}

    	for (int i = 0; i < g[last].size(); ++i)
    	{
    		int v = g[last][i];
    		if (!vis[v]) {
    			vis[v] = true;
    			plan[count] = v;

    			if (dfs2(v, count+1, tot, vis, plan))
    				return true;

    			vis[v] = false;
    		}
    	}

    	return false;
    }
};