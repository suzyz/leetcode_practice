// Bit manipulation.

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size(), curMax = 0, mask = 0;

        for (int i = 30; i >= 0; --i) {
            mask |= (1<<i);
            
            unordered_set<int> s;
            for (int j = 0; j < n; ++j)
                s.insert(nums[j] & mask);

            int possibleNewMax = curMax | (1<<i);
            for (unordered_set<int>::iterator it = s.begin();
                it != s.end(); ++it)
                if (s.count((*it) ^ possibleNewMax)) {
                    curMax = possibleNewMax;
                    break;
                }
        }
        
        return curMax;
    }
};