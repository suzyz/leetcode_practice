class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
        	return true;

        int l = 0, r = n-1;

        while (l < n-1 && nums[l+1] >= nums[l])
        	++l;

        if (l == n-1)
        	return true;

        while (r > 0 && nums[r-1] <= nums[r])
        	--r;

        if (r != l+1)
        	return false;

        if (l == 0 || r == n-1 || nums[l-1] <= nums[r] || nums[l] <= nums[r+1])
        	return true;
        else
        	return false;
    }
};
