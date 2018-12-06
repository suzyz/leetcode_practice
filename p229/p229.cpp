class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        
        if (n == 0)
            return res;
        if (n < 3) {
            res = nums;
            return res;
        }
        
        int v1 = nums[0], freq1 = 1, i = 1;
        while (i < n && nums[i] == v1) {
            ++freq1;
            ++i;
        }
        
        if (i == n) {
            res.push_back(v1);
            return res;
        }
        
        int v2 = nums[i], freq2 = 1;
        ++i;
        
        for ( ; i < n; ++i) {
            if (nums[i] == v1)
                ++freq1;
            else {
                --freq1;
            }
        }
            
    }
};