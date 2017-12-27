// DP. O(N^3).
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        long long total = 0;
        vector<long long> sum(n+1,0);

        for (int i = 1; i <= n; ++i)
        {
        	sum[i] = sum[i-1] + nums[i-1];
        	total += sum[i];
        }

        vector<vector<long long>> f(n+1,vector<long long>(m+1,total));
        f[0] = vector<long long>(m+1,0);
        for (int i = 1; i <= n; ++i)
        	for (int j = 1; j <= min(m,i); ++j)
        		for (int k = i-1; k >= j-1; --k)
        		{
        			if (sum[i] - sum[k] > f[i][j])
        				break;
        			f[i][j] = min(f[i][j],max(f[k][j-1],sum[i] - sum[k]));
        		}

        return f[n][m];
    }
};
