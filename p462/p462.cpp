// O(N*logN). Math.
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        long long ans;
        vector<long long> sum(n);
        sum[0] = nums[0];
        for (int i = 1; i < n; ++i)
            sum[i] = sum[i-1] + nums[i];
        
        for (int i = 1; i < n; ++i) {
            long long cur = sum[n-1] - sum[i-1]*2;
            long long d;
            
            if (2*i <= n)
                d = nums[i];
            else
                d = nums[i-1];
            
            d *= (2*i - n);
            
            cur += d;
            
            if (i == 1)
                ans = cur;
            else
                ans = min(ans, cur);
        }
        
        return ans;
    }
    
};