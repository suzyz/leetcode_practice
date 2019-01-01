// O(N^2)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        for (int i = n-1; i > 1; --i) {
            int a = nums[i], lo = 0, hi = i-1;
            while (lo < hi) {
                if (nums[lo] + nums[hi] > a) {
                    ans += hi-lo;
                    --hi;
                } else
                    ++lo;
            }
        }
        
        return ans;
    }
};