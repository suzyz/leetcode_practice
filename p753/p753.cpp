class Solution {
public:
	vector<string> s;
	unordered_map<string, int> idx;
	unordered_map<int, vector<pair<int, int>>> g;

    string crackSafe(int n, int k) {
        dfs1(0, n, k, "");

        int tot = s.size();
        for (int i = 0; i < tot; ++i)
        	for (int j = 0; j < tot; ++j)
        		if (i != j) {
        			for (int t = n-1; t >= 0; --t) {
        				bool ok = true;
        				for (int p = 0; p < t; ++p)
        					if (s[i][n-t+p] != s[j][p]) {
        						ok = false;
        						break;
        					}

        				if (ok) {
        					g[i].push_back(make_pair(j, t));
        					break;
        				}
        			}
        		}

        for (int i = 0; i < tot; ++i)
        {
        	vector<int> pre(tot, -1);
        	pre[i] = -2;
        	int maxL = dfs2(i, pre)
        }
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
};