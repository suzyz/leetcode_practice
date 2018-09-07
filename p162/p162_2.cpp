class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }

    	nums.insert(nums.begin(),INT_MIN);
    	nums.push_back(INT_MAX);

        int n = nums.size();
        int l = 1, r = n-2;

        while (l < r)
        {
        	int mid = l + ((r-l)>>1);

        	if (nums[mid] > nums[mid+1]) {
                r = mid;
            } else {
                l = mid+1;
            }
        }

        return l-1;
    }
};
