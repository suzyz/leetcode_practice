class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        if (n < 2)
        	return n;

        vector<vector<pair<int, int>>> ranges(26);
        int i = 0, j;
        while (i < n) {
        	j = i+1;
        	while (j < n && s[j] == s[i])
        		++j;

        	ranges[s[i]-'A'].push_back(make_pair(i, j));

        	i = j;
        }

        int ans = 0;
        for (int i = 0; i < 26; ++i)
        	if (ranges[i].size() > 0) {
	        	int l = 0, r = 1, cost = 0,
	        		len = ranges[i][0].second - ranges[i][0].first,
	        		lim = ranges[i].size();

	        	ans = max(ans, min(n, len + k));
                if (ans == n)
                    break;

	        	while (r < lim) {
	        		if (r <= l) {
	        			r = l+1;
	        			cost = 0;
	        			len = ranges[i][l].second - ranges[i][l].first;
	        		}

	        		while (r < lim && ranges[i][r].first - ranges[i][r-1].second + cost <= k) {
	        			cost += ranges[i][r].first - ranges[i][r-1].second;
	        			len += ranges[i][r].second - ranges[i][r-1].second;
	        			++r;
	        		}
                    
                    // printf("%d %d : %d %d\n", l, r, cost, len);

	        		ans = max(ans, min(n, len + k - cost));

	        		if (l < r-1) {
	        			cost -= ranges[i][l+1].first - ranges[i][l].second;
	        			len -= ranges[i][l+1].first - ranges[i][l].first;
	        		} else
	        			len -= ranges[i][l].second - ranges[i][l].first;

	        		++l;
	        	}

	        	if (ans == n)
	        		break;
	        }

        return ans;
    }
};