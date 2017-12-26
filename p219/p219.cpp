class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    	int n = nums.size();
        if (k <= 0 || n < 2)
        	return false;

        unordered_set<int> s;
        for (int i = 0; i < n; ++i)
        {
        	if (s.count(nums[i]))
        		return true;

        	s.insert(nums[i]);
        	if (i-k >= 0)
        		s.erase(nums[i-k]);
        }

        return false;
    }
};
