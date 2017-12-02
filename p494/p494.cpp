// Plain DP. Backpack.
class Solution {
public:
	const int base = 2002;
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        int f[22][base*2];
        memset(f,0,sizeof(f));

        int sum = 0;
        f[0][base] = 1;
        for (int i = 1; i <= n; ++i)
        {
        	sum += nums[i-1];
        	for (int j = -sum; j <= sum; ++j)
        		f[i][j+base] += f[i-1][j-nums[i-1]+base] + f[i-1][j+nums[i-1]+base];
        }

        if (S > sum || S < -sum)
        	return 0;

        return f[n][base+S];
    }
};
