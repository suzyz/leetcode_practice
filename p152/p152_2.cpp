class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        int maxp = nums[0], minp = nums[0], ans = nums[0];
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] < 0)
                swap(maxp,minp);

            maxp = max(nums[i], nums[i] * maxp);
            minp = min(nums[i], nums[i] * minp);

            ans = max(ans,maxp);
        }
        return ans;
    }
};
