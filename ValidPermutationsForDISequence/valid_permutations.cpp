// f[i][j]: the number of sequences that satisfy:
// 1. length is i+1,
// 2. the last number is the (j+1)th smallest number of the rest numbers.

class Solution {
public:
	int f[202][202];
    int numPermsDISequence(string S) {
        int n = S.length()+1;
        const int mo = 1000000007;

        memset(f, 0, sizeof(f));

        for (int i = 0; i < n; ++i)
        	f[0][i] = 1;

        for (int i = 1; i < n; ++i)
        {
        	for (int j = 0; j < n-i; ++j)
        	{
	        	if (S[i-1] == 'D')
	        		for (int k = j+1; k < n-i+1; ++k)
	        		{
	        			f[i][j] += f[i-1][k];
	        			if (f[i][j] >= mo)
	        				f[i][j] -= mo; 
	        		}
	        	else
	        		for (int k = 0; k <= j; ++k)
	        		{
	        			f[i][j] += f[i-1][k];
	        			if (f[i][j] >= mo)
	        				f[i][j] -= mo; 
	        		}
        	}
        }

        return f[n-1][0];
    }
};