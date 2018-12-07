class Solution {
public:
    int change(int amount, vector<int>& coins) {
    	int n = coins.size();

        vector<int> f(amount+1);

        f[0] = 1;
        for (int i = 0; i < n; ++i) {
        	int v = coins[i];
        	for (int j = v; j <= amount; ++j)
        		f[j] += f[j - v];
        }
        
        return f[amount];
    }
};