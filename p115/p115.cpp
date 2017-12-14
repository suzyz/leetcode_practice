
class Solution {
public:
	int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();

        if (n < m)
        	return 0;

        int f[n+1][m+1];
        memset(f,0,sizeof(f));
        for (int i = 0; i <= n; ++i)
        	f[i][0] = 1;

        for (int i = 1; i <= n; ++i)
        {
        	for (int j = 1; j <= min(i,m); ++j)
        	{
        		f[i][j] = f[i-1][j];
        		if (f[i-1][j-1] > 0 && s[i-1] == t[j-1])
        			f[i][j] += f[i-1][j-1];
        	}
        }
        return f[n][m];
    }
};
