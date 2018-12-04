class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0;

        for (int i = 0; i < k; ++i)
        	sum += nums[i];

        double ans = 1.0 * sum / k;

        for (int i = k; i < n; ++i) {
        	sum += nums[i] - nums[i-k];
        	ans = max(ans, 1.0 * sum / k);
        }

        return ans;
    }
};