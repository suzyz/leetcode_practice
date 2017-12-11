class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.push_back(1);
        for (int i = 0; i < n; ++i)
        	++nums[i];

        for (int i = 0; i < n; ++i)
        {
        	int k = abs(nums[i]);
        	if (k < 1 || k > n+1 || nums[k] < 0)
        		continue;

        	nums[k] *= -1;
        }

        for (int i = 1; i <= n+1; ++i)
        	if (nums[i] > 0)
        		return i-1;
        return 0;
    }
};
