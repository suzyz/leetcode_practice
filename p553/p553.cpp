class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        string ans = to_string(nums[0]);

        if (n == 1)
        	return ans;
        
       	ans += "/";

       	if (n == 2) {
       		ans += to_string(nums[1]);
       		return ans;
       	}

       	ans += "(" + to_string(nums[1]);

       	for (int i = 2; i < n; ++i)
       		ans += "/" + to_string(nums[i]);

       	ans += ")";

        return ans;
    }
};