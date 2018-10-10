// Based on version 1.
// DP + enumerate A's position.
// And a little space optimization.
const int maxn = 100002;

class Solution {
public:
	int f[3][2];
	long long g[maxn];
	const int mo = 1e9 + 7;

    int checkRecord(int n) {

    	f[1][0] = f[1][1] = 1;
    	f[2][0] = f[2][1] = 2;
        g[0] = 1;
        g[1] = 2;
        g[2] = 4;

        int cur = 0;
        for (int i = 3; i <= n; ++i)
        {
            int p1 = getPre(cur, 1), p2 = getPre(cur, 2);
        	f[cur][0] = addMod(f[p1][1], f[p2][1]);
        	f[cur][1] = addMod(f[p1][0], f[p1][1]);

        	g[i] = addMod(f[cur][0], f[cur][1]);

            cur = (cur+1)%3;
        }

        long long ans = g[n];
        for (int i = 1; i <= n; ++i)
        	ans = addMod(ans, g[i-1] * g[n-i] % mo);

       	return ans;
    }

    int addMod(int a, int b) {
        a += b;
        if (a >= mo)
            a -= mo;
        return a;
    }

    int getPre(int cur, int offset) {
        int res = cur - offset;
        if (res < 0)
            res += 3;
        return res;
    }
};