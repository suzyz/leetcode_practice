// O(N) time. O(1) space.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2)
        	return 0;
        
        int last_buy = -prices[0], last_sell = INT_MIN, cool_last_sell = INT_MIN;

        for (int i = 1; i < n; ++i)
        {
            int tmp = last_sell;
            
        	last_sell = max(last_sell, last_buy + prices[i]);
        	last_buy = max(last_buy, -prices[i]);
        	if (i > 2 && cool_last_sell > INT_MIN)
        		last_buy = max(last_buy, cool_last_sell - prices[i]);

            cool_last_sell = tmp;
        }

        return (last_sell > 0) ? last_sell:0;
    }
};
