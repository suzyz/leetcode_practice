// Brutal. O(N^3).
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
        	return 0;

        vector<vector<int>> f(n+1,vector<int>(n+1,0));

        int len = 1;
        for (int i = 1; i <= n; ++i)
        	f[i][1] = 1;

        for (int i = 1; i < n; ++i)
        {
        	for (int j = 1; j <= i; ++j)
        	{
        		if (f[i][j] == 0)
        			break;

        		for (int k = i+1; k <= n; ++k)
        			if (nums[i-1] < nums[k-1])
        			{
        				len = max(len,j+1);
        				f[k][j+1] += f[i][j];
        			}
        	}
        }

        int res = 0;
        for (int i = 1; i <= n; ++i)
        	res += f[i][len];

        return res;
    }
};
