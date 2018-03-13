class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for (int i = 0; i < n; ++i)
        	if (s.count(nums[i]))
        		return nums[i];
        	else
        		s.insert(nums[i]);

        return 0;
    }
};
