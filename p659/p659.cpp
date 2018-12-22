class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq, endWith;
        
        for (int i = 0; i < n; ++i)
            ++freq[nums[i]];
        
        for (int i = 0; i < n; ++i)
            if (freq[nums[i]] > 0) {
                int cur = nums[i];
                
                if (endWith[cur-1] > 0) {
                    --endWith[cur-1];
                    ++endWith[cur];
                    
                    --freq[cur];
                } else if (freq[cur+1] > 0 && freq[cur+2] > 0) {
                    ++endWith[cur+2];
                    
                    --freq[cur];
                    --freq[cur+1];
                    --freq[cur+2];
                } else
                    return false;
            }
        
        return true;
    }
};