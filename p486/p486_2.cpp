// 1. O(n^2) time and O(n) space.
// 2. Note that, facing 2*i numbers means winning for sure.
class Solution {
	public:
		bool PredictTheWinner(vector<int>& nums) {
			int n = nums.size();
			if (n < 2 || n%2 == 0)
				return true;

			int sum[22];

			sum[0] = 0;
			for (int i = 1; i <= n; ++i)
				sum[i] = sum[i-1] + nums[i-1];           

			int f[22];
			for (int i = 1; i <= n; ++i)
			 	f[i] = nums[i-1];

			 f[n+1] = 1<<20;
			
			int pre;
			for (int i = 2; i <= n; ++i)
				for (int st = 1; st <= n-i+1; ++st)
					f[st] = sum[st+i-1] - sum[st-1] - min(f[st+1], f[st]);
			
			return 2*f[1] >= sum[n];
		}
};
