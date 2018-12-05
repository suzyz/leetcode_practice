class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for (int i = 0; i < nums.size(); ++i)
            s.insert(nums[i]);
        
        set<int>::reverse_iterator rit = s.rbegin();
        if (s.size() < 3)
            return *rit;
        
        ++rit;
        ++rit;
        
        return *rit;
    }
};