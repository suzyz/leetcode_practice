//
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        int sum = 0;
        for (int i = 1; i <= n; ++i)
        	sum += nums[i-1];
        if (S > sum || S < -sum || (S+sum)%2 != 0)
            return 0;
        	
        int target = (sum + S) >> 1;
        vector<int> f(target+1,0);
        f[0] = 1;
        for (int i = 0; i < n; ++i)
            for (int j = target; j >= nums[i]; --j)
                f[j] += f[j-nums[i]];

        return f[target];
    }
};
