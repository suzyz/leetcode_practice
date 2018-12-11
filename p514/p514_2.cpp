class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.length(), m = key.length();

        vector<vector<int>> pos(26);

        for (int i = 0; i < n; ++i)
        	pos[ring[i]-'a'].push_back(i);

        vector<vector<pair<int,int>>> f(m+1);
        f[0].push_back(make_pair(0, 0));

        int ans = 1e6;
        for (int i = 0; i < m; ++i) {
        	int cur = key[i] - 'a';

        	for (int j = 0; j < pos[cur].size(); ++j) {
                int mind = 1e6, p1 = pos[cur][j];

                for (int k = 0; k < f[i].size(); ++k) {
                    int p2 = f[i][k].first, d = f[i][k].second;

                    mind = min(mind, d + min(abs(p1-p2), n-abs(p1-p2)));
                }

                if (i == m-1)
                    ans = min(ans, mind);
                else
                    f[i+1].push_back(make_pair(p1, mind));
            }
        }

        return ans + m;
    }
};