class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> now;
        vector<vector<int>> res;
        dfs(0,n,now,nums,res);
        return res;
    }

    void dfs(int cur,int n,vector<int> &now,vector<int> &nums,vector<vector<int>> &res)
    {
    	if (cur == n)
    	{
    		res.push_back(now);
    		return;
    	}

    	dfs(cur+1,n,now,nums,res);

    	now.push_back(nums[cur]);
    	dfs(cur+1,n,now,nums,res);
    	now.pop_back();
    }
};
