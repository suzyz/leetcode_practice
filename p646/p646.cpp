// Sort + Plain DP. O(n^2)
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        sort(pairs.begin(), pairs.end());

        vector<int> f(n+1, 1);

        for (int i = 1; i < n; ++i)
        {
        	for (int j = i-1; j >= 0; --j)
        		if (pairs[j][1] < pairs[i][0])
        			f[i] = max(f[i], f[j]+1);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
        	ans = max(ans, f[i]);

        return ans;
    }
};