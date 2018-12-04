class Solution {
public:
	unordered_map<int, int> m;
    int findPairs(vector<int>& nums, int k) {
    	if (k < 0)
        	return 0;
        
        int n = nums.size(), ans = 0;
		
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
        	int target = nums[i] - k;
        	if (m[target] == 1) {
        		++ans;
        		++m[target];
        	}

        	if (m[nums[i]] == 0)
        		m[nums[i]] = 1;
        }

        return ans;
    }
};