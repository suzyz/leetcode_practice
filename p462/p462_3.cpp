// O(N). Median!!!
// Use quick select to find "median".

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return 0;
        
        int ans = 0, target = findKth(0, n-1, n/2, nums);
        
        for (int i = 0; i < n; ++i)
            ans += abs(nums[i] - target);
        
        return ans;
    }
    
    int findKth(int st, int en, int k, vector<int> &nums) {
        if (st == en)
            return nums[st];
        
        int idx = st, pos = st + rand()%(en-st+1);
        swap(nums[pos], nums[en]);
        
        for (int i = st; i < en; ++i)
            if (nums[i] < nums[en]) {
                swap(nums[idx], nums[i]);
                ++idx;
            }
        
        swap(nums[idx], nums[en]);
        
        if (k == idx-st)
            return nums[idx];
        if (k < idx-st)
            return findKth(st, idx-1, k, nums);
        else
            return findKth(idx+1, en, k-(idx-st)-1, nums);
    }
    
};