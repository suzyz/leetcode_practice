class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        if (n < 2)
        	return n;

        vector<int> f(n, 1);

        for (int len = 2; len <= n; ++len)
      		for (int i = n-len; i >= 0; --i) {
      			if (s[i] == s[i + len - 1])
      				f[i] = max(f[i], f[i+1] + 2);
      			else
      				f[i] = max(f[i], f[i+1]);
      		}

      	return f[0];
    }
};