// DP. O(N^3) time.
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        if (n == 0)
        	return true;

        int f[102][102];
        memset(f, 0, sizeof(f));

        for (int i = 0; i < n; ++i)
        {
        	if (s[i] == '*')
        		f[i][i] = true;

        	if (i < n-1)
        		if ((s[i] == '(' && s[i+1] == ')')
        			|| (s[i] == '(' && s[i+1] == '*')
        			|| (s[i] == '*' && s[i+1] == ')')
        			|| (s[i] == '*' && s[i+1] == '*'))
        			f[i][i+1] = true;
        }
        
        for (int i = 3; i <= n; ++i) {
        	for (int st = 0; st <= n-i; ++st) {
        		int en = st+i-1;

        		if (f[st+1][en-1])
        			if ((s[st] == '(' && s[en] == ')')
	        			|| (s[st] == '(' && s[en] == '*')
	        			|| (s[st] == '*' && s[en] == ')')
	        			|| (s[st] == '*' && s[en] == '*'))
	        			f[st][en] = true;

	        	if (!f[st][en])
	        		for (int k = st; k < en; ++k)
	        			if (f[st][k] && f[k+1][en]) {
	        				f[st][en] = true;
	        				break;
	        			}
        	}
        }

        return f[0][n-1];
    }
};