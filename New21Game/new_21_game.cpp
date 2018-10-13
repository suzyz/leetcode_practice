class Solution {
public:
	double f[10002];
    double new21Game(int N, int K, int W) {
    	if (K == 0)
    		return 1.0;

    	N = min(N, K + W - 1);

        f[0] = 1.0;
        double sum = f[0];
        for (int i = 1; i <= N; ++i)
        {
        	f[i] = sum/W;

        	if (i < K)
        		sum += f[i];

        	if (i >= W)
        		sum -= f[i-W];
        }

        double ans = 0;
        for (int i = K; i <= N; ++i)
        	ans += f[i];

        return ans;
    }
};