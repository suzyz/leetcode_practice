class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    	int n = nums.size();
        int res = n+1;
        int st = 0, en = -1, sum = 0;

        while (en < n-1)
        {
        	++en;
        	sum += nums[en];

        	if (sum >= s)
        	{
        		while (st < en && sum - nums[st] >= s)
        		{
        			sum -= nums[st];
        			++st;
        		}
        		res = min(res,en-st+1);
        	}
        }

        return res == n+1 ? 0:res;
    }
};
