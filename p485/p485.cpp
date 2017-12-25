class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), i = 0, res = 0;

        while (i < n)
        {
        	if (nums[i] == 1)
        	{
        		int st = i;
        		++i;
        		while (i < n && nums[i] == 1)
        			++i;

        		res = max(res,i-st);
        	}
        	else
        		++i;
        }

        return res;
    }
};
