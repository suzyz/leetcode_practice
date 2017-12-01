// Plain DP. O(N^2) space.
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        if (n == 0)
        	return 0;

        int count = n;
        vector<vector<bool>> f(n+1,vector<bool>(n,false));

        for (int i = 0; i < n; ++i)
        	f[0][i] = f[1][i] = true;

        for (int i = 2; i <= n; ++i)
        	for (int j = 0; j <= n-i ; ++j)
        		if (s[j] == s[j+i-1])
        		{
        			if (f[i-2][j+1])
        			{
        				f[i][j] = true;
        				++count;
        			}
        		}

        return count;
    }
};
