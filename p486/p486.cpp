// Plain. O(n^2) time and O(n^2) space.
class Solution {
	public:
		bool PredictTheWinner(vector<int>& nums) {
			int n = nums.size();
			if (n < 2)
				return true;

			int sum[22];

			sum[0] = 0;
			for (int i = 1; i <= n; ++i)
				sum[i] = sum[i-1] + nums[i-1];           

			int f[22][22];
			for (int i = 1; i <= n; ++i)
			 	f[i][i] = nums[i-1];
			
			for (int i = 2; i <= n; ++i)
				for (int st = 1; st <= n-i+1; ++st)
				{
					int en = st+i-1;
					f[st][en] = sum[en] - sum[st-1] - min(f[st+1][en], f[st][en-1]);
				}
			
			return 2*f[1][n] >= sum[n];
		}
};
