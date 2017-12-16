class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k == 0 || n == 0)
        	return 0;

        if (k > (n>>1))
        	k = n>>1;

        int f[k+1][2];
        memset(f,0,sizeof(f));

        for (int i = 1; i <= n; ++i)
        	for (int j = 1; j <= min((i+1)/2,k); ++j)
        	{
        		if (i >= 2*j)
        			f[j][0] = max(f[j][0],f[j-1][1] - prices[i-1]);
        		else
        			f[j][0] = f[j-1][1] - prices[i-1];

        		if (i >= 2*j + 1)
					f[j][1] = max(f[j][1],f[j][0] + prices[i-1]);
				else
					f[j][1] = f[j][0] + prices[i-1];
        	}

        int res = 0;
        for (int i = 1; i <= k; ++i)
        	res = max(res,f[k][1]);
        
        return res;
    }
};
