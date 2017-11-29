class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();

        int f[m+2];
        f[0] = 0;
        
        for (int i = 1; i <= m; ++i)
        	f[i] = i;

        for (int i = 1; i <= n; ++i)
        {
            int pre = f[0];
            f[0] = i;
            for (int j = 1; j <= m; ++j)
            {
                int cur = f[j]; //f[i-1][j];
                f[j] = min(f[j],f[j-1]) + 1; //min(f[i-1][j],f[i][j-1]) + 1;
                if (word1[i-1] == word2[j-1])
                    f[j] = min(f[j],pre); //min(f[i][j],f[i-1][j-1]);
                else
                    f[j] = min(f[j],pre+1); //min(f[i][j],f[i-1][j-1]+1);
                pre = cur;
            }            
        }

        return f[m];
    }
};
