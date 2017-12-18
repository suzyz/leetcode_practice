class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
        	return 0;
        if (n == 1)
        	return nums[0];

        return max(helper(0,n-2,nums),helper(1,n-1,nums));
    }

    int helper(int st,int en,vector<int> &nums)
    {
    	int pre1 = 0, pre2 = 0, cur, res = 0;
    	for (int i = st; i <= en; ++i)
    	{
    		cur = max(pre1,pre2 + nums[i]);
    		res = max(res,cur);

    		pre2 = pre1;
    		pre1 = cur;
    	}

    	return res;
    }
};
