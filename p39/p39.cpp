// DFS. Each time, search the number of the current candidate in the combination.
class Solution {
private:
	int n = 0;
	vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    	sort(candidates.begin(),candidates.end());
    	while (candidates.size() > 0 && candidates.back() > target)
    		candidates.pop_back();

        n = candidates.size();
        vector<int> nums(n,0);
        dfs(0,target,candidates,nums);

        return res;
    }

    void dfs(int cur,int target,vector<int>& candidates,vector<int>& nums)
    {
    	if (target == 0)
    	{
    		vector<int> r;
    		for (int i = 0; i < n; ++i)
    			for (int j = 0; j < nums[i]; ++j)
    				r.push_back(candidates[i]);
    		res.push_back(r);
    		return;
    	}

    	if (cur >= n || target < 0)
    		return;

    	for (int i = 0; i <= target/candidates[cur]; ++i)
    	{
    		nums[cur] = i;
    		dfs(cur+1,target - i*candidates[cur],candidates,nums);
    	}
    }
};
