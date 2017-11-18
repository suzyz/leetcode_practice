class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    	if (amount < 0)
    		return -1;
    	if (amount == 0)
    		return 0;

        int n = coins.size(), f[amount+2];
        memset(f,-1,sizeof(f));

        f[0] = 0;
        for (int i = 0; i < n; ++i)
        	for (int j = coins[i]; j <= amount; ++j)
        		if (f[j-coins[i]] != -1)
        		{
        			if (f[j] == -1)
        				f[j] = f[j-coins[i]]+1;
        			else
        				f[j] = min(f[j],f[j-coins[i]]+1);
        		}

        return f[amount];
    }
};