class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        
        if (n == 0)
            return res;
        
        int v1 = nums[0], freq1 = 1, v2 = INT_MIN, freq2 = 0;
        
        for (int i = 1 ; i < n; ++i) {
            if (nums[i] == v1)
                ++freq1;
            else {
                if (nums[i] == v2)
                    ++freq2;
                else
                    if (freq1 == 0) {
                        v1 = nums[i];
                        freq1 = 1;
                    } else if (freq2 == 0) {
                        v2 = nums[i];
                        freq2 = 1;
                    } else {
                        --freq1;
                        --freq2;
                    }
            }
        }
        
        freq1 = freq2 = 0;
        for (int i = 0; i < n; ++i)
            if (nums[i] == v1)
                ++freq1;
            else if (nums[i] == v2)
                ++freq2;
        
        if (freq1 > n/3)
            res.push_back(v1);
        if (freq2 > n/3)
            res.push_back(v2);
        
        return res;
    }
};