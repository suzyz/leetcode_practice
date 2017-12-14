// Using unordered set.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
        	return n;

        int res = 1;
        unordered_set<int> borders(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i)
        	if (borders.count(nums[i]))
        	{
        		int l = nums[i]-1, r = nums[i]+1;
                while (borders.count(l) == 1)
                {
                    borders.erase(l);
                    --l;
                }

                while (borders.count(r) == 1)
                {
                    borders.erase(r);
                    ++r;
                }

                ++l;
                --r;
                res = max(res,r-l+1);
        	}

        return res;
    }
};
