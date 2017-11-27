class Solution {
public:
    int numSquares(int n) {
        int f[n+2];
        
        for (int i = 0; i <= n; ++i)
        	f[i] = i;

        for (int i = 2; i <= sqrt(n); ++i)
        {
        	int sq = i*i;
        	for (int j = 0; j <= n-sq; ++j)
        		if (f[j+sq] > f[j] + 1)
        			f[j+sq] = f[j] + 1;
        }
        return f[n];
    }
};
