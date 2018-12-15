// DP. O(N^2).
class Solution {
public:
    int minSteps(int n) {
        vector<int> f(n+1);

        f[1] = 0;
        for (int i = 2; i <= n; ++i) {
        	if (i%2 == 0)
        		f[i] = f[i/2] + 2;
        	else {
				f[i] = i;

        		for (int j = i-1; j > 1; --j)
        			if (i%j == 0)
        				f[i] = min(f[i], f[j] + i/j);
        	}
        }

        return f[n];
    }
};