class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int rob_last = 0, not_rob_last = 0;
        for (int i = 0; i < n; ++i)
        {
        	int tmp = max(rob_last,not_rob_last);

        	rob_last = not_rob_last + nums[i];
        	not_rob_last = tmp;
        }

        return max(rob_last,not_rob_last);
    }
};
