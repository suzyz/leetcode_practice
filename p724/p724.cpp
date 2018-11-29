class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size(), sum = 0, tot = 0;
        for (int i = 0; i < n; ++i)
        	tot += nums[i];

        for (int i = 0; i < n; ++i)
        	if (sum == tot - sum - nums[i])
        		return i;
        	else
        		sum += nums[i];

        return -1;
    }
};