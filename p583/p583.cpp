class Solution {
public:

    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length(), flag = 0;
        vector<vector<int>> f(2, vector<int>(m+1, 0));

        for (int i = 1; i <= n; ++i) {
        	for (int j = 1; j <= m; ++j) {
        		if (word1[i-1] == word2[j-1])
        			f[flag][j] = f[1-flag][j-1]+1;
        		else
        			f[flag][j] = max(f[1-flag][j], f[flag][j-1]);
        	}

        	flag = 1-flag;
        }

        return n - f[1-flag][m] + m - f[1-flag][m];
    }
};