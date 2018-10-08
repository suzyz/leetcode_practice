class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();

        int ans = A[0];

        vector<int> sum(n+1);
        int minPreSum = 0;
        for (int i = 1; i <= n; ++i)
        {
        	sum[i] = sum[i-1] + A[i-1];
        	ans = max(ans, sum[i] - minPreSum);
        	minPreSum = min(minPreSum, sum[i]);
        }

        int maxPostSum = 0, tot = sum[n];
        for (int i = n; i > 0; --i) {
        	ans = max(ans, sum[i] + maxPostSum);
        	maxPostSum = max(maxPostSum , tot - sum[i-1]);
        }

        return ans;
    }
};