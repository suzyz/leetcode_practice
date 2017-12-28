// O(N) time. O(N) space.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2)
        	return 0;

        // f[i]: the max amount of money on day i, if the last transaction is selling.
        // g[i]: the max amount of money on day i, if the last transaction is buying.

        vector<int> f(n,INT_MIN),g(n,INT_MIN);
        g[0] = -prices[0];

        for (int i = 1; i < n; ++i)
        {
        	f[i] = max(f[i-1], g[i-1] + prices[i]);
        	g[i] = max(g[i-1], -prices[i]);
        	if (i > 2 && f[i-2] > INT_MIN)
        		g[i] = max(g[i], f[i-2] - prices[i]);
        }

        return (f[n-1] > 0) ? f[n-1]:0;
    }
};
