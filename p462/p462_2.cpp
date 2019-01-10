// O(N*logN). Median!!!
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int ans = 0, i = 0, j = n-1;
        while (i < j) {
            ans += nums[j] - nums[i];
            ++i;
            --j;
        }
        
        return ans;
    }
    
};