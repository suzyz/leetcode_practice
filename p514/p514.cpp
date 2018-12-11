class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.length(), m = key.length();

        vector<vector<int>> pos(26), f(m+1, vector<int>(n, -1));

        for (int i = 0; i < n; ++i)
        	pos[ring[i]-'a'].push_back(i);

        f[0][0] = 0;
        for (int i = 0; i < m; ++i) {
        	int cur = key[i] - 'a';

        	for (int j = 0; j < n; ++j)
        		if (f[i][j] != -1) {
        			for (int k = 0; k < pos[cur].size(); ++k) {
        				int p = pos[cur][k];
        				int tmp = f[i][j] + min(abs(p-j), n-abs(p-j)) + 1;

        				if (f[i+1][p] == -1 || f[i+1][p] > tmp)
        					f[i+1][p] = tmp;
        			}
        		}
        }

        int ans = 1e6;
        for (int j = 0; j < n; ++j)
        	if (f[m][j] != -1 && f[m][j] < ans)
        		ans = f[m][j];

        return ans;
    }
};