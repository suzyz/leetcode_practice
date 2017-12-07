// Iterative.

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        res.push_back(vector<int>());

        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; )
        {
            int dup = 0;
            while (i + dup < n && nums[i+dup] == nums[i])
                ++dup;

            int sum = res.size();
            for (int k = 0; k < sum; ++k)
            {
                vector<int> cur = res[k];
                for (int j = 1; j <= dup; ++j)
                {
                    cur.push_back(nums[i]);
                    res.push_back(cur);
                }   
            }

            i += dup;
        }

        return res;
    }
};
