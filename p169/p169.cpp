class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
        	return 0;
        int e = nums[0], freq = 1;
        for (int i = 1; i < n; ++i)
        {
        	if (nums[i] == e)
        		++freq;
        	else
        	{
        		--freq;
        		if (freq < 0)
        		{
        			e = nums[i];
        			freq = 1;
        		}
        	}
        }

        return e;
    }
};
