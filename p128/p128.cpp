// Using set.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
        	return n;

        int res = 1;
        map<int,int> len;
        for (int i = 0; i < n; ++i)
        	if (!len.count(nums[i]))
        	{
        		int l = len.count(nums[i]-1) == 0 ? 0:len[nums[i]-1];
        		int r = len.count(nums[i]+1) == 0 ? 0:len[nums[i]+1];
        		int s = l+r+1;
        		res = max(res,s);
        		len[nums[i]] = len[nums[i]-l] = len[nums[i]+r] = s;
        	}

        return res;
    }
};
