class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        if (n==0)
       	{
       		for (int i = 0; i < m; ++i)
       			if (p[i] != '*')
       				return false;
       		return true;
       	}

        bool f[n+2][m+2];
        memset(f,0,sizeof(f));

        f[0][0] = true;
        for (int j = 1; j <= m && p[j-1] == '*'; ++j)
        	f[0][j] = true;
        
        for (int i = 1; i <= n; ++i)
        	for (int j = 1; j <= m; ++j)
        	{
        		if (s[i-1] == p[j-1] || p[j-1] == '?')
        			f[i][j] = f[i-1][j-1];
        		if (p[j-1] == '*')
        			f[i][j] |= f[i][j-1] | f[i-1][j-1] | f[i-1][j];
        	}
        
        return f[n][m];
    }
};
