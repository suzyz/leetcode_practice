class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    	nums.insert(nums.begin(),INT_MIN);
    	nums.push_back(INT_MAX);

        int n = nums.size();

        int l = 1, r = n-2;
        if (l >= r)
        	return 0;

        while (l < r)
        {
        	int mid = l + ((r-l)>>1);

        	if (nums[mid] >= nums[mid-1] && nums[mid] >= nums[mid+1])
        		return mid-1;
        	else
        	if (nums[mid-1] <= nums[mid] && nums[mid] <= nums[mid+1])
        		l = mid+1;
        	else
        		r = mid-1;
        }

        return l-1;
    }
};
