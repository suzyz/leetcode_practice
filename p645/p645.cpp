class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    	vector<int> res(2,0);
    	unordered_set<int> s;

    	int n = nums.size();
    	for (int i = 0; i < n; ++i)
    		if (s.count(nums[i]))
    			res[0] = nums[i];
    		else
    			s.insert(nums[i]);

    	for (int i = 1; i <= n; ++i)
    		if (s.count(i) == 0)
    		{
    			res[1] = i;
    			break;
    		}
    	
    	return res;
    }
};
