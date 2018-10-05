class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        for (int i = 0; i < n; ++i)
        {
        	int cur = nums[i];
        	if (cur < 0)
        		cur = -cur;

        	if (nums[cur-1] < 0)
        		res.push_back(cur);
        	else
        		nums[cur-1] = -nums[cur-1];
        }

        return res;
    }
};