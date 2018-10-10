// DP + enumerate A's position.
const int maxn = 100002;

class Solution {
public:
	int f[maxn][2];
	long long g[maxn];
	const int mo = 1e9 + 7;

    int checkRecord(int n) {

    	f[1][0] = f[1][1] = 1;
    	f[2][0] = f[2][1] = 2;
        for (int i = 3; i <= n; ++i)
        {
        	f[i][0] = (f[i-1][1] + f[i-2][1])%mo;
        	f[i][1] = (f[i-1][0] + f[i-1][1])%mo;

        	g[i] = (f[i][0] + f[i][1])%mo;
        }

        g[0] = 1;
        g[1] = 2;
        g[2] = 4;

        long long ans = (f[n][0] + f[n][1])%mo;
        for (int i = 1; i <= n; ++i)
        	ans = (ans + g[i-1] * g[n-i] % mo)%mo;

       	return ans;
    }
};