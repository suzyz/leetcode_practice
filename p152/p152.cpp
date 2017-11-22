class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max_neg = INT_MIN, product = 1, ans = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
        	if (nums[i] == 0)
        	{
        		ans = max(ans,0);
        		max_neg = INT_MIN;
        		product = 1;
        	}
        	else
        	{
        		product *= nums[i];
        		ans = max(ans,product);
        		if (product < 0 && max_neg > INT_MIN)
        			ans = max(ans,product/max_neg);

        		if (product < 0)
        			max_neg = max(max_neg,product);
        	}
        }
        return ans;
    }
};
